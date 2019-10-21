#include <condition_variable>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>
#include <queue>


void writeToFile(std::string input)
{
    std::ofstream file("console-output.txt", std::ofstream::out | std::ofstream::app);
    if (file.is_open())
    {
        file << input;
    }
    else
    {
        std::cout << "Don't forget an else path if you open a file!" << std::endl;
    }
}

int main ()
{
    std::queue<std::string> produced_input;
    std::mutex mtx;
    std::condition_variable cond_var;
    bool is_done = false;
    bool is_notified = false;
    bool console_has_close = false;

    std::thread producer ([&]() {
        while(!console_has_close)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::unique_lock<std::mutex> lock(mtx);
            std::cout << "Write something..." << std::endl;
            std::string input;
            std::cin >> input;
            input += "\n"; // Each new line after nen returned input
            produced_input.push(input);
            is_notified = true;
            cond_var.notify_one();
        }
    });

    std::thread consumer([&]() {
        std::unique_lock<std::mutex> lock(mtx);
        while(!console_has_close)
        {
            while (!is_notified) 
            {
                cond_var.wait(lock);
            }
            while (!produced_input.empty())
            {
                writeToFile(produced_input.front());
                produced_input.pop();
            }
            is_notified = false;
        }
    });

    producer.join();
    consumer.join();
}