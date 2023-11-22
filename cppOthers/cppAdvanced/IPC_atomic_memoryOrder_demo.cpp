#include <atomic>
/*
Memory order is a concept associated with atomic operations on variables in multithreaded programming. It specifies the constraints on the order in which memory operations are perceived by different threads. In C++, memory order is controlled using the std::memory_order enumeration, which provides different levels of synchronization.
*/

// memory_order_relaxed: No ordering or synchronization constraints are imposed on other reads or writes.
std::atomic<int> x(0);
x.load(std::memory_order_relaxed);


// memory_order_consume: The operation is a consume operation. This memory order is deprecated, and its use is discouraged.

// memory_order_acquire: Ensures that all memory operations before the load operation are completed before the load is executed.
std::atomic<int> y(0);
int value = y.load(std::memory_order_acquire);


// memory_order_release: Ensures that all memory operations after the store operation are not executed until the store is completed.
std::atomic<int> p(42);
p.store(23, std::memory_order_release);


// memory_order_acq_rel: Combines the effects of both memory_order_acquire and memory_order_release.
std::atomic<int> q(0);
q.exchange(42, std::memory_order_acq_rel);


// memory_order_seq_cst: The strongest ordering, providing sequential consistency. All operations are sequentially consistent with respect to all other sequentially consistent operations.

std::atomic<int> r(0);
int value = r.load(std::memory_order_seq_cst);

/*
When working with atomic operations, it's crucial to choose the appropriate memory order based on the desired synchronization guarantees and the specific requirements of your program. The choice of memory order impacts performance and the level of synchronization between threads. Generally, memory_order_seq_cst provides the strongest guarantees but may incur higher performance costs compared to more relaxed memory orders.
*/