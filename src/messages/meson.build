 fs = import('fs')
protobuf_sub = subproject('protobuf')
protoc_native = protobuf_sub.get_variable('protoc_native')
protobuf_dep = dependency('protobuf', fallback: ['protobuf', 'protobuf_dep'])


proto_files = [
  'proto/hello.proto',

]

proto_targets = []
foreach file  : proto_files
  proto_targets += custom_target(
    input: file,
    build_by_default: true,
    output: ['@BASENAME@.pb.cc', '@BASENAME@.pb.h'],
    command: [protoc_native, '--proto_path=@CURRENT_SOURCE_DIR@/proto', '--cpp_out=@OUTDIR@', '@INPUT@'],
    install: true,
    install_dir: [false, 'include']
  )
endforeach

messages_lib = library('messages', 
  sources: proto_targets ,
  dependencies: [
    protobuf_dep
  ],
  install: true
)

messages_dep = declare_dependency(
  link_with: messages_lib,
  include_directories: include_directories('.'),
  dependencies: [
    protobuf_dep
  ]
)
meson.override_dependency('messages', messages_dep)