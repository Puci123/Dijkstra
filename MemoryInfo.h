//#pragma once
//#include <memory>
//#include <iostream>
//
//namespace memory_info
//{
//
//	struct AllocationInfo
//	{
//		void* addr;
//		size_t size;
//	};
//
//
//	static constexpr int defaultAllocArraySize = 2;
//
//
//	inline unsigned long long int total_allocs = 0;
//	inline unsigned long long int current_allocs = 0;
//	inline unsigned long long int total_memory_usage = 0;
//
//	inline memory_info::AllocationInfo** allocs = nullptr;
//	inline unsigned long long int allocsSize = memory_info::defaultAllocArraySize;
//
//	static void onNewAllocUpdate(void*& ptr,std::size_t size);
//	static void onDeleteUpdate(void*& ptr, char flag);
//	static memory_info::AllocationInfo* createAlloaction(void*& ptr, std::size_t size);
//	static void pushToAllocationArray(memory_info::AllocationInfo*&);
//	static memory_info::AllocationInfo* popFromAllocationArray(void*& target);
//	static void printMemInfo();
//
//}
//
//
//inline void* operator new(size_t size)
//{
//	void* ptr = malloc(size);
//	memory_info::onNewAllocUpdate(ptr, size);
//	return ptr;
//}
//
//inline void* operator new[](size_t size)
//{
//	void* ptr = malloc(size);
//	memory_info::onNewAllocUpdate(ptr, size);
//	return ptr;
//}
//
//inline void operator delete(void* ptr, size_t size) noexcept
//{
//	memory_info::onDeleteUpdate(ptr, 'S');
//	free(ptr);
//}
//
//inline void  operator delete[](void* ptr, size_t size)  noexcept
//{
//	memory_info::onDeleteUpdate(ptr, 'X');
//	free(ptr);
//}
//
//inline void operator delete(void* ptr) noexcept
//{
//	memory_info::onDeleteUpdate(ptr,'N');
//	free(ptr);
//}
//
//inline void  operator delete[](void* ptr)  noexcept
//{
//	memory_info::onDeleteUpdate(ptr,'A');
//	free(ptr);
//}
//
//
//void memory_info::onDeleteUpdate(void*& ptr, char flag)
//{
//	current_allocs--;
//	memory_info::AllocationInfo* data = popFromAllocationArray(ptr);
//
//	if (data != nullptr) 
//	{
//		//std::cout << "Free memory: " << data->size << std::endl;
//		memory_info::total_memory_usage -= static_cast<unsigned long long int>(data->size);
//		std::cout << "Free memory: " << (data->size) << " " << flag << std::endl;
//	}
//}
//
//void memory_info::onNewAllocUpdate(void*& ptr, std::size_t size) 
//{
//	std::cout << "Aloc memory: " << size << std::endl;
//	memory_info::AllocationInfo* newAlloc = createAlloaction(ptr, size);
//	memory_info::total_allocs++;
//	memory_info::current_allocs++;
//	memory_info::total_memory_usage += static_cast<unsigned long long int>(size);
//
//
//	pushToAllocationArray(newAlloc);
//}
//
//memory_info::AllocationInfo* memory_info::createAlloaction(void*& ptr, std::size_t size)
//{
//	memory_info::AllocationInfo* newAlloc = (memory_info::AllocationInfo*)malloc(sizeof(memory_info::AllocationInfo));
//	
//	newAlloc->addr = ptr;
//	newAlloc->size = size;
//
//	return newAlloc;
//}
//
//void memory_info::pushToAllocationArray(memory_info::AllocationInfo*& newAlloc) 
//{
//	if (memory_info::allocs == nullptr) 
//	{
//		memory_info::allocs = (memory_info::AllocationInfo**)calloc(memory_info::allocsSize, sizeof(memory_info::AllocationInfo*));
//		for (unsigned long long int i = 0; i < memory_info::allocsSize; i++)
//		{
//			memory_info::allocs[i] = nullptr;
//		}
//	}
//
//	if (memory_info::allocsSize <= memory_info::current_allocs) 
//	{
//		int newAllocSize = memory_info::allocsSize * 2;
//		memory_info::AllocationInfo** temp = (memory_info::AllocationInfo**)calloc(newAllocSize, sizeof(memory_info::AllocationInfo*));
//
//		for (unsigned long long int i = 0; i < memory_info::allocsSize; i++)
//		{
//			temp[i] = memory_info::allocs[i];
//		}
//
//		for (unsigned long long int i = memory_info::allocsSize; i < newAllocSize; i++)
//		{
//			temp[i] = nullptr;
//		}
//
//		free(memory_info::allocs);
//		memory_info::allocsSize = newAllocSize;
//		memory_info::allocs = temp;
//	}
//
//	memory_info::allocs[memory_info::current_allocs - 1] = newAlloc;
//}
//
//memory_info::AllocationInfo* memory_info::popFromAllocationArray(void*& target)
//{
//	memory_info::AllocationInfo* otput = nullptr;
//
//	for (int i = 0; i < memory_info::current_allocs - 1; i++)
//	{
//		if (memory_info::allocs[i]->addr == target) 
//		{
//			otput = memory_info::allocs[i];
//		}
//		else if(otput != nullptr)
//		{
//			memory_info::allocs[i - 1] = memory_info::allocs[i];
//		}
//	}
//
//
//	return otput;
//}
//
//void memory_info::printMemInfo() 
//{
//	std::cout << std::endl << "############ Memory usage ############" << std::endl;
//	std::cout << "Curent memory usage: " << memory_info::total_memory_usage << " b" << std::endl;
//	std::cout << "Curent allocations: " << memory_info::current_allocs << std::endl;
//	std::cout << "Total allocations: " << memory_info::total_allocs << std::endl;
//	std::cout << "###############################################################" << std::endl;
//
//
//}
