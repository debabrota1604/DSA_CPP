#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
#include <iomanip>
#include <unordered_map>

// Removes double include erorrs
#ifndef CPU_PROFILER_HPP
#define CPU_PROFILER_HPP

#define MAX_COUNTER_INSTANCES UINT_MAX
#define cyclecount_t uint64_t
#define index_t unsigned int
#define MAX_INSTANCE_SIZE 20
#define PROFILER_INSTANCE_DUMP_FILE "cpuProfilerOutput_"

class TagObj {
protected:
    std::string name;
    cyclecount_t startTime, stopTime;
    std::vector<cyclecount_t> durationInstances;
    uint64_t lastValidIndex, lostSamples;

public:
    TagObj(std::string name, unsigned int maxCounters) : name(name) {
        lastValidIndex = -1;
        lostSamples = 0;

        // resetting the output file
        std::ofstream outfile;
        std::cout << "Deleting old data files...\n";
        outfile.open(PROFILER_INSTANCE_DUMP_FILE + this->name + ".txt", std::ios::trunc);
        outfile.close();
    }

    static inline cyclecount_t readTimestampCounter() {
        uint64_t lo, hi;
        asm volatile("rdtscp" : "=a"(lo), "=d"(hi) : : "%ebx", "%ecx");
        cyclecount_t res = hi;
        res = res << 32;
        res |= lo;
        return res;
    }

    inline void pushDuration() {
        if (this->startTime == 0)
            std::cout << "ERROR: counter for tag " << this->name << " not started\n";

        lastValidIndex++;
        durationInstances.emplace_back(this->stopTime - this->startTime);
    }

    inline void printVector(std::vector<cyclecount_t> inp) {
        for (auto item : inp) {
            std::cout << item << ", ";
        }
        std::cout << std::endl;
    }

    inline cyclecount_t getDuration(int index) { return durationInstances[index]; }

    inline index_t getEntriesCount() { return lastValidIndex; }

    inline void Start() { this->startTime = readTimestampCounter(); }

    inline void Stop() { this->stopTime = readTimestampCounter(); pushDuration(); }

    void prepareReportAndDumpToFile() {
        std::cout << std::setw(10) << this->name << ":: ";

        /* Dump raw profiler data to file */
        std::ofstream outfile(PROFILER_INSTANCE_DUMP_FILE + this->name + ".txt", std::ios::app);

        for (const auto& duration : durationInstances) {
            outfile << duration << "\n";
        }
        std::sort(durationInstances.begin(), durationInstances.end());

        // Calculate statistical values
        size_t totalCount = durationInstances.size();
        if (totalCount == 0) {
            std::cerr << "No duration instances to report.\n";
            return;
        }

        cyclecount_t min_val = durationInstances.front();
        cyclecount_t max_val = durationInstances.back();
        cyclecount_t median_val = durationInstances[totalCount / 2];
        cyclecount_t prcntle_90 = durationInstances[totalCount * 90 / 100];
        cyclecount_t prcntle_95 = durationInstances[totalCount * 95 / 100];
        cyclecount_t prcntle_99 = durationInstances[totalCount * 99 / 100];
        cyclecount_t prcntle_999 = durationInstances[totalCount * 999 / 1000];

        double mean_val = std::accumulate(durationInstances.begin(), durationInstances.end(), 0.0) / totalCount;

        // Output statistical information
        std::cout << " Mean: " << std::dec << std::setw(8) << std::setfill(' ') << mean_val
                << " Median: " << std::setw(8) << median_val
                << " 90th: " << std::setw(8) << prcntle_90
                << " 95th: " << std::setw(8) << prcntle_95
                << " 99th: " << std::setw(8) << prcntle_99
                << " 99.9th: " << std::setw(8) << prcntle_999
                << " Min: " << std::setw(8) << min_val
                << " Max: " << std::setw(8) << max_val
                << " Count: " << totalCount
                << std::endl;

        // Output to file
        outfile << this->name << ":: "
                << " Mean: " << int(mean_val)
                << " Median: " << median_val
                << " 90th: " << prcntle_90
                << " 95th: " << prcntle_95
                << " 99th: " << prcntle_99
                << " 99.9th: " << prcntle_999
                << " Min: " << min_val
                << " Max: " << max_val
                << " Count: " << totalCount
                << std::endl;

        outfile.close();
    }

    void prepareReportAndDumpToFile_hex() {
        std::cout << std::setw(10) << this->name << ":: ";

        /* dump raw profiler data to file*/
        std::ofstream outfile;
        outfile.open(PROFILER_INSTANCE_DUMP_FILE + this->name + ".txt", std::ios::app);

        for (size_t iter = 0; iter < durationInstances.size(); iter++) {
            outfile << std::hex << std::setw(10) << std::setfill('0') << durationInstances[iter] << "\n";
        }
        std::sort(durationInstances.begin(), durationInstances.end());

        //printVector(durationInstances);

        cyclecount_t median_val, prcntle_90, prcntle_95, prcntle_99, prcntle_999, min_val, max_val, totalCount;
        totalCount = durationInstances.size();
        min_val = durationInstances.front();
        max_val = durationInstances.back();

        median_val = durationInstances[totalCount / 2];
        prcntle_90 = durationInstances[totalCount * 90 / 100];
        prcntle_95 = durationInstances[totalCount * 95 / 100];
        prcntle_99 = durationInstances[totalCount * 99 / 100];
        prcntle_999 = durationInstances[totalCount * 999 / 1000];

        double mean_val = 0;
        for (cyclecount_t iter = 0; iter < durationInstances.size(); iter++) {
            mean_val += ((double)durationInstances[iter]) / totalCount;
        }

        std::cout << " Mean: " << std::setw(8) << std::setfill('0') << std::hex << int(mean_val)
                << " Median: " << std::setw(8) << median_val
                << " 90th: " << std::setw(8) << prcntle_90
                << " 95th: " << std::setw(8) << prcntle_95
                << " 99th: " << std::setw(8) << prcntle_99
                << " 99.9th: " << std::setw(8) << prcntle_999
                << " Min: " << std::setw(8) << min_val
                << " Max: " << std::setw(8) << max_val
                << " Count: " << totalCount
                << std::endl;
        
        // std::cout << " Indices Considered: " << totalCount << ": "
        //           << " Median: " << std::setw(8) << totalCount / 2
        //           << " 90th: " << std::setw(8) << totalCount * 90 / 100
        //           << " 95th: " << std::setw(8) << totalCount * 95 / 100
        //           << " 99th: " << std::setw(8) << totalCount * 99 / 100
        //           << " 99.9th: " << std::setw(8) << totalCount * 999 / 1000
        //           << " Min: " << std::setw(8) << totalCount *0
        //           << " Max: " << std::setw(8) << totalCount *1 -1
        //           << " Count: " << totalCount
        //           << std::endl;

        outfile << this->name << ":: "
                << " Mean: " << int(mean_val)
                << " Median: " << median_val
                << " 90th: " << prcntle_90
                << " 95th: " << prcntle_95
                << " 99th: " << prcntle_99
                << " 99.9th: " << prcntle_999
                << " Min: " << min_val
                << " Max: " << max_val
                << " Count: " << totalCount
                << std::endl;

        outfile.close(); 
    }


    void prepareSummary() {
        // resize vector to valid data points
        durationInstances.resize(lastValidIndex + 1);
        std::sort(durationInstances.begin(), durationInstances.end());

        cyclecount_t mean_val, median_val, prcntle_90, prcntle_95, prcntle_99, prcntle_999, min_val, max_val, totalCount;
        totalCount = durationInstances.size();
        min_val = durationInstances.front();
        max_val = durationInstances.back();
        median_val = durationInstances[totalCount / 2];
        prcntle_90 = durationInstances[totalCount * (90 / 100)];
        prcntle_95 = durationInstances[totalCount * (95 / 100)];
        prcntle_99 = durationInstances[totalCount * (99 / 100)];
        prcntle_999 = durationInstances[totalCount * (999 / 1000)];

        for (cyclecount_t iter = 0; iter < durationInstances.size(); iter++) {
            // avoiding overflow
            durationInstances[iter] /= totalCount;
        }
        mean_val = std::accumulate(durationInstances.begin(), durationInstances.end(), 0);

        std::cout << std::setw(10) << this->name << ":: "
                  << " Mean: " << std::setw(10) << mean_val
                  << " Median: " << std::setw(10) << median_val
                  << " 90th: " << std::setw(10) << prcntle_90
                  << " 95th: " << std::setw(10) << prcntle_95
                  << " 99th: " << std::setw(10) << prcntle_99
                  << " 99.9th: " << std::setw(10) << prcntle_999
                  << " Min: " << std::setw(10) << min_val
                  << " Max: " << std::setw(10) << max_val
                  << " Count: " << std::setw(5) << totalCount
                  << std::endl;
    }
};

class CpuProfiler { // Singleton class
private:
    unsigned int maxInstancesPerCounter; // configurable params
    std::unordered_map<std::string, TagObj*> tags; // for O(1) lookup instead of O(n) traversal through vector

    CpuProfiler(unsigned int maxCounters) : maxInstancesPerCounter(maxCounters) {
        std::cout << "CpuProfiler Constructor Called.\n";
    }

public:
    static CpuProfiler& getUniqueInstance(unsigned int maxCounters = MAX_COUNTER_INSTANCES) {
        static CpuProfiler* profilerObj = nullptr;
        if (nullptr == profilerObj) {
            profilerObj = new CpuProfiler(maxCounters);
        }
        return *profilerObj;
    }

    void addTag(std::string name) {
        TagObj* t = new TagObj(name, this->maxInstancesPerCounter);
        tags[name] = t;
    }

    void prepareReportAndDumpToFile() {
        for (auto iter = tags.begin(); iter != tags.end(); ++iter) {
            (*iter->second).prepareReportAndDumpToFile();
        }
    }
    void prepareReportAndDumpToFile_hex() {
        for (auto iter = tags.begin(); iter != tags.end(); ++iter) {
            (*iter->second).prepareReportAndDumpToFile_hex();
        }
    }

    void prepareReport() {
        for (auto iter = tags.begin(); iter != tags.end(); ++iter) {
            (*iter->second).prepareSummary();
        }
    }

    TagObj& getTagObj(std::string name) {
        return *(tags[name]);
    }

    void startTag(std::string tagName) {
        TagObj* tag = tags.at(tagName);
        if (tag == nullptr) {
            std::cout << "Tag " << tagName << " not found...\n";
            return;
        }

        tag->Start();
    }

    void stopTag(std::string tagName) {
        TagObj* tag = tags.at(tagName);
        if (tag == nullptr) {
            std::cout << "Tag " << tagName << " not found...\n";
            return;
        }

        tag->Stop();
    }
};



#endif