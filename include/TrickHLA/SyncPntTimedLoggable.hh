/*!
@file TrickHLA/LoggableTimedSyncPnt.hh
@ingroup TrickHLA
@brief This class provides a mechanism for logging timed synchronization point
data and retrieving it from the log file.

@copyright Copyright 2019 United States Government as represented by the
Administrator of the National Aeronautics and Space Administration.
No copyright is claimed in the United States under Title 17, U.S. Code.
All Other Rights Reserved.

\par<b>Responsible Organization</b>
Simulation and Graphics Branch, Mail Code ER7\n
Software, Robotics & Simulation Division\n
NASA, Johnson Space Center\n
2101 NASA Parkway, Houston, TX  77058

@trick_parse{everything}

@python_module{TrickHLA}

@revs_title
@revs_begin
@rev_entry{Tony Varesic, L3, TrickHLA, July 2009, --, Checkpoint / restore of TrickHLA.}
@rev_entry{Dan Dexter, NASA ER7, TrickHLA, March 2019, --, Version 2 origin.}
@rev_entry{Edwin Z. Crues, NASA ER7, TrickHLA, March 2019, --, Version 3 rewrite.}
@revs_end

*/

#ifndef TRICKHLA_LOGGABLE_TIMED_SYNC_PNT_HH
#define TRICKHLA_LOGGABLE_TIMED_SYNC_PNT_HH

// System include files.
#include <cstdint>

// Trick include files.
#include "trick/memorymanager_c_intf.h"

// TrickHLA include files.
#include "TrickHLA/LoggableSyncPnt.hh"

namespace TrickHLA
{

class LoggableTimedSyncPnt : public TrickHLA::LoggableSyncPnt
{
   // Let the Trick input processor access protected and private data.
   // InputProcessor is really just a marker class (does not really
   // exists - at least yet). This friend statement just tells Trick
   // to go ahead and process the protected and private data as well
   // as the usual public data.
   friend class InputProcessor;
   // IMPORTANT Note: you must have the following line too.
   // Syntax: friend void init_attr<namespace>__<class name>();
   friend void init_attrTrickHLA__LoggableTimedSyncPnt();

  public:
   /*! @brief Default constructor for the TrickHLA LoggableTimedSyncPnt class. */
   LoggableTimedSyncPnt() : time( 0 )
   {
      return;
   }
   /*! @brief Destructor for the TrickHLA LoggableTimedSyncPnt class. */
   ~LoggableTimedSyncPnt()
   {
      return;
   }

  public:
   int64_t time; ///< @trick_units{--} Freeze time.

  private:
   // Do not allow the copy constructor or assignment operator.
   /*! @brief Copy constructor for LoggableTimedSyncPnt class.
    *  @details This constructor is private to prevent inadvertent copies. */
   LoggableTimedSyncPnt( LoggableTimedSyncPnt const &rhs );
   /*! @brief Assignment operator for LoggableTimedSyncPnt class.
    *  @details This assignment operator is private to prevent inadvertent copies. */
   LoggableTimedSyncPnt &operator=( LoggableTimedSyncPnt const &rhs );
};

} // namespace TrickHLA

#endif /* TRICKHLA_LOGGABLE_TIMED_SYNC_PNT_HH */
