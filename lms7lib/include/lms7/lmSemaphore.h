/**
@file lms7/lmSemaphore.h
@author Lime Microsystems
@brief Wrapper class for semaphores
*/

#ifndef LM_SEMAPHORE_H
#define LM_SEMAPHORE_H

#include <lms7/Config.h>

#ifdef __unix__
    #include <semaphore.h>
#endif

///Wrapper class for semaphores in Windows and Linux
class LMS7_API lmSemaphore
{
public:
    lmSemaphore();
    ~lmSemaphore();
    #ifndef __unix__
        void* m_sem;
        long m_semCount;
    #else
        sem_t m_sem;
    #endif // __unix__
};

LMS7_API int lmCreateSemaphore(lmSemaphore &sem, int initialCount, int maxCount);
LMS7_API int lmDestroySemaphore(lmSemaphore &sem);
LMS7_API int lmSem_wait(lmSemaphore &sem, unsigned long timeout_ms);
LMS7_API int lmSem_post(lmSemaphore &sem);
LMS7_API int lmSem_getvalue(lmSemaphore &sem);

#endif // LM_SEMAPHORE_H
