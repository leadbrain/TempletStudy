#include <stdio.h>
#include "tbb/parallel_for.h"
#include "tbb/blocked_range.h"

class PrintJob {
public:
  void operator()(const tbb::blocked_range<size_t>& r) const {
    const float* local_pointer = job_buffer_;
    for (size_t i = r.begin(); i != r.end(); ++i) {
      printf("%d : %f\n", i, local_pointer[i]);
    }
  }

  PrintJob(float buffer[]) : job_buffer_(buffer) {}

private:
  const float* job_buffer_;
};

int main(int argc, char* arvg[]) {
  const int kBin = 10;
  float buffer[kBin] = {0.0f, };

  tbb::parallel_for(tbb::blocked_range<size_t>(0, kBin), PrintJob(buffer));

  return 0;
}
