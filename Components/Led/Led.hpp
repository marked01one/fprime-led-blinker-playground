// ======================================================================
// \title  Led.hpp
// \author marked01one
// \brief  hpp file for Led component implementation class
// ======================================================================

#ifndef Components_Led_HPP
#define Components_Led_HPP

#include <Fw/Types/OnEnumAc.hpp>
#include "Components/Led/LedComponentAc.hpp"
#include <Os/Mutex.hpp>

namespace Components {

  class Led :
    public LedComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct Led object
      Led(
          const char* const compName //!< The component name
      );

      //! Destroy Led object
      ~Led();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for run
      //!
      //! Port receiving calls from the rate group
      void run_handler(
          const NATIVE_INT_TYPE portNum, //!< The port number
          NATIVE_UINT_TYPE context //!< The call order
      );
    

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command
      //!
      void BLINKING_ON_OFF_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          Fw::On on_off //!< Indicates whether the blinking should be on or off
      );

      //! Emit parameter updated EVR
      //!
      void parameterUpdated(FwPrmIdType id /*!< The parameter ID*/);

      Os::Mutex lock;
      Fw::On state;
      U64 transitions;
      U32 count;
      bool blinking;


  };

}

#endif
