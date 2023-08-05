std::shared_ptr<X> global; // initially nullptr
// Note that concurrent access to the pointers, not to the values they refer to, is meant.
void foo()
{
	std::shared_ptr<X> local{ new X };
	...
		std::atomic_store(&global, local);
}