/*!
@file TrickHLA/ObjectDeleted.hh
@ingroup TrickHLA
@brief This class is the abstract base class for a callback of identification
of deleted objects from the RTI.

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

@tldh
@trick_link_dependency{../../source/TrickHLA/ObjectDeleted.cpp}
@trick_link_dependency{../../source/TrickHLA/Object.cpp}

@revs_title
@revs_begin
@rev_entry{Tony Varesic, L3-Communications, DSES, June 2008, --, IMSim: report TrickHLA::Object as deleted via a callback.}
@rev_entry{Dan Dexter, NASA ER7, TrickHLA, March 2019, --, Version 2 origin.}
@rev_entry{Edwin Z. Crues, NASA ER7, TrickHLA, March 2019, --, Version 3 rewrite.}
@rev_entry{Dan Dexter, NASA ER6, TrickHLA, November 2023, --, Added initialize_callback().}
@revs_end

*/

#ifndef TRICKHLA_OBJECT_DELETED_HH
#define TRICKHLA_OBJECT_DELETED_HH

// TrickHLA include files.
#include "TrickHLA/Object.hh"

namespace TrickHLA
{
// Forward Declared Classes:  Since these classes are only used as references
// through pointers, these classes are included as forward declarations. This
// helps to limit issues with recursive includes.
class Object;

class ObjectDeleted
{
   // Let the Trick input processor access protected and private data.
   // InputProcessor is really just a marker class (does not really
   // exists - at least yet). This friend statement just tells Trick
   // to go ahead and process the protected and private data as well
   // as the usual public data.
   friend class InputProcessor;
   // IMPORTANT Note: you must have the following line too.
   // Syntax: friend void init_attr<namespace>__<class name>();
   friend void init_attrTrickHLA__ObjectDeleted();

  public:
   //-----------------------------------------------------------------
   // Constructors / destructors
   //-----------------------------------------------------------------
   /*! @brief Default constructor for the TrickHLA ObjectDeleted class. */
   ObjectDeleted();
   /*! @brief Destructor for the TrickHLA ObjectDeleted class. */
   virtual ~ObjectDeleted();

   // Use implicit copy constructor and assignment operator.

   //-----------------------------------------------------------------
   // These are a virtual functions and must be defined by a full class.
   //-----------------------------------------------------------------

   /*! @brief Initialize the callback object to the supplied Object pointer.
    *  @param obj Associated object for this class. */
   virtual void initialize_callback( Object *obj );

   /*! @brief Callback informing that the object instance was deleted. */
   virtual void deleted() = 0;

  protected:
   Object *object; ///< @trick_io{**} Object associated with this class.
};

} // namespace TrickHLA

#endif // TRICKHLA_OBJECT_DELETED_HH: Do NOT put anything after this line!
