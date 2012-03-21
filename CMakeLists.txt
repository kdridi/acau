CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(acau)

SET (ACAU_CXX_COMPILER	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang)
SET (ACAU_CXX_FLAGS     " -x c++ -arch x86_64 -fmessage-length=0 -Wno-trigraphs -fpascal-strings -O0 -Wno-missing-field-initializers -Wno-missing-prototypes -Wno-return-type -Wno-non-virtual-dtor -Wno-overloaded-virtual -Wno-exit-time-destructors -Wformat -Wno-missing-braces -Wparentheses -Wswitch -Wno-unused-function -Wno-unused-label -Wno-unused-parameter -Wno-unused-variable -Wunused-value -Wno-uninitialized -Wno-unknown-pragmas -Wno-shadow -Wno-four-char-constants -Wno-sign-compare -Wno-shorten-64-to-32 -Wno-newline-eof -Wc++11-extensions -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk -fasm-blocks -Wdeprecated-declarations -Winvalid-offsetof -mmacosx-version-min=10.5 -g -fvisibility-inlines-hidden -Wno-conversion -Wno-sign-conversion -Wmost -Wno-four-char-constants -Wno-unknown-pragmas -MMD -MT dependencies")

#SET (ACAU_CXX_COMPILER /usr/bin/g++)
#SET (ACAU_CXX_FLAGS "-Werror -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk")

SET (ACAU_CXX_FLAGS     "-x c++ -arch armv7 -fmessage-length=0 -Wno-trigraphs -fpascal-strings -O0 -Wno-missing-field-initializers -Wmissing-prototypes -Wreturn-type -Wno-non-virtual-dtor -Wno-overloaded-virtual -Wno-exit-time-destructors -Wformat -Wno-missing-braces -Wparentheses -Wswitch -Wno-unused-function -Wno-unused-label -Wno-unused-parameter -Wunused-variable -Wunused-value -Wno-uninitialized -Wno-unknown-pragmas -Wno-shadow -Wno-four-char-constants -Wno-sign-compare -Wno-shorten-64-to-32 -Wno-newline-eof -Wc++11-extensions -DDEBUG=1 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS5.1.sdk -Wdeprecated-declarations -Winvalid-offsetof -g -fvisibility-inlines-hidden -Wno-conversion -Wno-sign-conversion -mthumb -miphoneos-version-min=5.0 -MMD -MT dependencies ")

SET (CMAKE_CXX_FLAGS	${ACAU_CXX_FLAGS})
SET (CMAKE_CXX_COMPILER	${ACAU_CXX_COMPILER})

MESSAGE (STATUS ${CMAKE_CXX_FLAGS})
MESSAGE (STATUS ${CMAKE_CXX_COMPILER})

ADD_LIBRARY (
	acau
	##CoreAudio/AudioCodecs/ACPublic/ACBaseCodec.cpp
	##CoreAudio/AudioCodecs/ACPublic/ACCodec.cpp
	CoreAudio/AudioCodecs/ACPublic/ACPlugInDispatch.cpp
	##CoreAudio/AudioCodecs/ACPublic/ACSimpleCodec.cpp
	CoreAudio/AudioCodecs/ACPublic/GetCodecBundle.cpp
	##CoreAudio/AudioFile/AFPublic/AudioFileComponentBase.cpp
	CoreAudio/AudioFile/AFPublic/AudioFileFormat.cpp
	CoreAudio/AudioFile/AFPublic/AudioFileObject.cpp
	CoreAudio/AudioFile/AFPublic/CompressedPacketTable.cpp
	CoreAudio/AudioFile/AFPublic/DataSource.cpp
	##CoreAudio/AudioUnits/AUPublic/AUBase/AUBase.cpp
	##CoreAudio/AudioUnits/AUPublic/AUBase/AUDispatch.cpp
	##CoreAudio/AudioUnits/AUPublic/AUBase/AUInputElement.cpp
	##CoreAudio/AudioUnits/AUPublic/AUBase/AUOutputElement.cpp
	##CoreAudio/AudioUnits/AUPublic/AUBase/AUPlugInDispatch.cpp
	##CoreAudio/AudioUnits/AUPublic/AUBase/AUScopeElement.cpp
	##CoreAudio/AudioUnits/AUPublic/AUBase/ComponentBase.cpp
	##CoreAudio/AudioUnits/AUPublic/AUCarbonViewBase/AUCarbonViewBase.cpp
	##CoreAudio/AudioUnits/AUPublic/AUCarbonViewBase/AUCarbonViewControl.cpp
	##CoreAudio/AudioUnits/AUPublic/AUCarbonViewBase/AUCarbonViewDispatch.cpp
	##CoreAudio/AudioUnits/AUPublic/AUCarbonViewBase/AUControlGroup.cpp
	##CoreAudio/AudioUnits/AUPublic/AUCarbonViewBase/CarbonEventHandler.cpp
	##CoreAudio/AudioUnits/AUPublic/AUInstrumentBase/AUInstrumentBase.cpp
	##CoreAudio/AudioUnits/AUPublic/AUInstrumentBase/SynthElement.cpp
	##CoreAudio/AudioUnits/AUPublic/AUInstrumentBase/SynthNote.cpp
	##CoreAudio/AudioUnits/AUPublic/AUInstrumentBase/SynthNoteList.cpp
	##CoreAudio/AudioUnits/AUPublic/OtherBases/AUEffectBase.cpp
	##CoreAudio/AudioUnits/AUPublic/OtherBases/AUMIDIBase.cpp
	#CoreAudio/AudioUnits/AUPublic/OtherBases/AUMIDIEffectBase.cpp
	##CoreAudio/AudioUnits/AUPublic/OtherBases/AUOutputBase.cpp
	##CoreAudio/AudioUnits/AUPublic/OtherBases/AUPannerBase.cpp
	##CoreAudio/AudioUnits/AUPublic/OtherBases/MusicDeviceBase.cpp
	##CoreAudio/AudioUnits/AUPublic/Utility/AUBaseHelper.cpp
	CoreAudio/AudioUnits/AUPublic/Utility/AUBuffer.cpp
	CoreAudio/AudioUnits/AUPublic/Utility/AUTimestampGenerator.cpp
	##CoreAudio/HAL/HPBase/HP_Command.cpp
	##CoreAudio/HAL/HPBase/HP_Control.cpp
	#CoreAudio/HAL/HPBase/HP_Device.cpp
	##CoreAudio/HAL/HPBase/HP_DeviceCommands.cpp
	##CoreAudio/HAL/HPBase/HP_DriverPlugIn.cpp
	##CoreAudio/HAL/HPBase/HP_FormatList.cpp
	##CoreAudio/HAL/HPBase/HP_HardwarePlugIn.cpp
	##CoreAudio/HAL/HPBase/HP_HardwarePlugInInterface.cpp
	##CoreAudio/HAL/HPBase/HP_HogMode.cpp
	##CoreAudio/HAL/HPBase/HP_IOCycleTelemetry.cpp
	#CoreAudio/HAL/HPBase/HP_IOProcList.cpp
	#CoreAudio/HAL/HPBase/HP_IOThread.cpp
	##CoreAudio/HAL/HPBase/HP_Object.cpp
	##CoreAudio/HAL/HPBase/HP_PreferredChannels.cpp
	##CoreAudio/HAL/HPBase/HP_Property.cpp
	CoreAudio/HAL/HPBase/HP_ReferenceCounted.cpp
	##CoreAudio/HAL/HPBase/HP_Stream.cpp
	#CoreAudio/HAL/HPBase/HP_SystemInfo.cpp
	##CoreAudio/HAL/HPBase/HP_TelemetryServer.cpp
	CoreAudio/PublicUtility/AUOutputBL.cpp
	##CoreAudio/PublicUtility/AUParamInfo.cpp
	CoreAudio/PublicUtility/CAAudioBufferList.cpp
	CoreAudio/PublicUtility/CAAudioChannelLayout.cpp
	CoreAudio/PublicUtility/CAAudioChannelLayoutObject.cpp
	CoreAudio/PublicUtility/CAAudioFileFormats.cpp
	CoreAudio/PublicUtility/CAAudioTimeStamp.cpp
	CoreAudio/PublicUtility/CAAudioUnit.cpp
	CoreAudio/PublicUtility/CAAudioValueRange.cpp
	##CoreAudio/PublicUtility/CAAUMIDIMap.cpp
	##CoreAudio/PublicUtility/CAAUMIDIMapManager.cpp
	##CoreAudio/PublicUtility/CAAUParameter.cpp
	CoreAudio/PublicUtility/CAAUProcessor.cpp
	CoreAudio/PublicUtility/CABufferList.cpp
	CoreAudio/PublicUtility/CABundleLocker.cpp
	CoreAudio/PublicUtility/CACFArray.cpp
	CoreAudio/PublicUtility/CACFDictionary.cpp
	CoreAudio/PublicUtility/CACFDistributedNotification.cpp
	CoreAudio/PublicUtility/CACFMachPort.cpp
	CoreAudio/PublicUtility/CACFMessagePort.cpp
	CoreAudio/PublicUtility/CACFNumber.cpp
	CoreAudio/PublicUtility/CACFPreferences.cpp
	CoreAudio/PublicUtility/CACFString.cpp
	CoreAudio/PublicUtility/CAComponent.cpp
	CoreAudio/PublicUtility/CAComponentDescription.cpp
	CoreAudio/PublicUtility/CADebugger.cpp
	CoreAudio/PublicUtility/CADebugMacros.cpp
	CoreAudio/PublicUtility/CADebugPrintf.cpp
	#CoreAudio/PublicUtility/CAFilePathUtils.cpp
	CoreAudio/PublicUtility/CAGuard.cpp
	##CoreAudio/PublicUtility/CAHALAudioDevice.cpp
	##CoreAudio/PublicUtility/CAHALAudioObject.cpp
	##CoreAudio/PublicUtility/CAHALAudioStream.cpp
	##CoreAudio/PublicUtility/CAHALAudioSystemObject.cpp
	CoreAudio/PublicUtility/CAHostTimeBase.cpp
	CoreAudio/PublicUtility/CAMutex.cpp
	##CoreAudio/PublicUtility/CAPersistence.cpp
	#CoreAudio/PublicUtility/CAProcess.cpp
	CoreAudio/PublicUtility/CAPThread.cpp
	CoreAudio/PublicUtility/CARingBuffer.cpp
	CoreAudio/PublicUtility/CASettingsStorage.cpp
	CoreAudio/PublicUtility/CASharedLibrary.cpp
	CoreAudio/PublicUtility/CASpectralProcessor.cpp
	CoreAudio/PublicUtility/CAStreamBasicDescription.cpp
	##CoreAudio/PublicUtility/CAStreamRangedDescription.cpp
	CoreAudio/PublicUtility/CAVectorUnit.cpp
	CoreAudio/PublicUtility/CAVolumeCurve.cpp
	CoreAudio/PublicUtility/CAXException.cpp
	##CoreAudio/PublicUtility/MatrixMixerVolumes.cpp
)

INSTALL(TARGETS acau
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

