class MemoryPool
{
    private:
        void *AllignedMemoryPointer;
        void *OriginalMemoryPointer;
        int PoolID;
        MemoryPool* PrevPool;
        MemoryPool* NextPool;

    public:
        // default constructor
        MemoryPool();
        
        // constructor
        MemoryPool(int ID, void* original, void* alligned);

        // destructor
        ~MemoryPool();

        // getter function for OriginalMemoryPointer
        void* GetOriginalMemoryStart();

        // getter function for PoolID
        int GetPoolID();

        // getter function for next pool memory pointer
        MemoryPool* GetNextPool();

        // getter function for previous pool memory pointer
        MemoryPool* GetPrevPool();

        // setter function for next pool memory pointer
        void SetNextPool(MemoryPool* next);

        // setter function for previous pool memory pointer
        void SetPrevPool(MemoryPool* prev);



};