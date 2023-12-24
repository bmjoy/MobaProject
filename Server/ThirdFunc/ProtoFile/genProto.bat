protoc SSToCS.proto --cpp_out=../MsgLists
protoc SSToGS.proto --cpp_out=../MsgLists

protoc GSToBS.proto --cpp_out=../MsgLists
protoc GSToSS.proto --cpp_out=../MsgLists
protoc GSToCS.proto --cpp_out=../MsgLists
protoc GSToGC.proto --cpp_out=../MsgLists

protoc BSToLS.proto --cpp_out=../MsgLists
protoc BSToGS.proto --cpp_out=../MsgLists
protoc BSToGC.proto --cpp_out=../MsgLists

protoc GCToLS.proto --cpp_out=../MsgLists
protoc GCToBS.proto --cpp_out=../MsgLists
protoc GCToCS.proto --cpp_out=../MsgLists
protoc GCToSS.proto --cpp_out=../MsgLists

protoc CSToSS.proto --cpp_out=../MsgLists
protoc CSToGS.proto --cpp_out=../MsgLists
protoc CSToRC.proto --cpp_out=../MsgLists

protoc LSToBS.proto --cpp_out=../MsgLists
protoc LSToGC.proto --cpp_out=../MsgLists

protoc RCToCS.proto --cpp_out=../MsgLists

protoc CSToDB.proto --cpp_out=../MsgLists
protoc DBToCs.proto --cpp_out=../MsgLists

protoc LSToSDK.proto --cpp_out=../MsgLists
protoc SDKToLS.proto --cpp_out=../MsgLists

protoc ToLog.proto --cpp_out=../MsgLists

protogen -I:GCToLS.proto -o:../ClientProtobuf/GCToLS.cs
protogen -I:GCToSS.proto -o:../ClientProtobuf/GCToSS.cs
protogen -I:GCToCS.proto -o:../ClientProtobuf/GCToCS.cs
protogen -I:GCToBS.proto -o:../ClientProtobuf/GCToBS.cs
protogen -I:GSToGC.proto -o:../ClientProtobuf/GSToGC.cs
protogen -I:BSToGC.proto -o:../ClientProtobuf/BSToGC.cs
protogen -I:LSToGC.proto -o:../ClientProtobuf/LSToGC.cs

protogen -I:CSToRC.proto -o:../RemoteProtobuf/CSToRC.cs
protogen -I:RCToCS.proto -o:../RemoteProtobuf/RCToCS.cs

cd ../ClientProtobuf 
copy * /Y ..\..\..\Client\Assets\ProtobuMsg
copy ..\RemoteProtobuf\CSToRC.cs /Y ..\..\RemoteConsole\RemoteConsole
copy ..\RemoteProtobuf\RCToCS.cs /Y ..\..\RemoteConsole\RemoteConsole
pause