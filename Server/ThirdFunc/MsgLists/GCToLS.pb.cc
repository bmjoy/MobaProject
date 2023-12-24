// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GCToLS.proto
// Protobuf C++ Version: 4.26.0-dev

#include "GCToLS.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace GCToLS {

inline constexpr AskLogin::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        uin_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        sessionid_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        platform_{0u},
        msgid_{static_cast< ::GCToLS::MsgID >(40961)} {}

template <typename>
PROTOBUF_CONSTEXPR AskLogin::AskLogin(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct AskLoginDefaultTypeInternal {
  PROTOBUF_CONSTEXPR AskLoginDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~AskLoginDefaultTypeInternal() {}
  union {
    AskLogin _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 AskLoginDefaultTypeInternal _AskLogin_default_instance_;
}  // namespace GCToLS
static ::_pb::Metadata file_level_metadata_GCToLS_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_GCToLS_2eproto[1];
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_GCToLS_2eproto = nullptr;
const ::uint32_t
    TableStruct_GCToLS_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::GCToLS::AskLogin, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::GCToLS::AskLogin, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::GCToLS::AskLogin, _impl_.msgid_),
        PROTOBUF_FIELD_OFFSET(::GCToLS::AskLogin, _impl_.platform_),
        PROTOBUF_FIELD_OFFSET(::GCToLS::AskLogin, _impl_.uin_),
        PROTOBUF_FIELD_OFFSET(::GCToLS::AskLogin, _impl_.sessionid_),
        3,
        2,
        0,
        1,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 12, -1, sizeof(::GCToLS::AskLogin)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::GCToLS::_AskLogin_default_instance_._instance,
};
const char descriptor_table_protodef_GCToLS_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\014GCToLS.proto\022\006GCToLS\"s\n\010AskLogin\0225\n\005ms"
    "gid\030\001 \001(\0162\r.GCToLS.MsgID:\027eMsgToLSFromGC"
    "_AskLogin\022\020\n\010platform\030\002 \001(\r\022\013\n\003uin\030\003 \001(\t"
    "\022\021\n\tsessionid\030\004 \001(\t*\\\n\005MsgID\022\032\n\024eMsgToLS"
    "FromGC_Begin\020\200\300\002\022\035\n\027eMsgToLSFromGC_AskLo"
    "gin\020\201\300\002\022\030\n\022eMsgToLSFromGC_End\020\212\300\002"
};
static ::absl::once_flag descriptor_table_GCToLS_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_GCToLS_2eproto = {
    false,
    false,
    233,
    descriptor_table_protodef_GCToLS_2eproto,
    "GCToLS.proto",
    &descriptor_table_GCToLS_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_GCToLS_2eproto::offsets,
    file_level_metadata_GCToLS_2eproto,
    file_level_enum_descriptors_GCToLS_2eproto,
    file_level_service_descriptors_GCToLS_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_GCToLS_2eproto_getter() {
  return &descriptor_table_GCToLS_2eproto;
}
namespace GCToLS {
const ::google::protobuf::EnumDescriptor* MsgID_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_GCToLS_2eproto);
  return file_level_enum_descriptors_GCToLS_2eproto[0];
}
PROTOBUF_CONSTINIT const uint32_t MsgID_internal_data_[] = {
    0u, 196608u, 40961u, 40960u, 40970u, };
bool MsgID_IsValid(int value) {
  return ::_pbi::ValidateEnum(value, MsgID_internal_data_);
}
// ===================================================================

class AskLogin::_Internal {
 public:
  using HasBits = decltype(std::declval<AskLogin>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(AskLogin, _impl_._has_bits_);
};

AskLogin::AskLogin(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:GCToLS.AskLogin)
}
inline PROTOBUF_NDEBUG_INLINE AskLogin::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        uin_(arena, from.uin_),
        sessionid_(arena, from.sessionid_) {}

AskLogin::AskLogin(
    ::google::protobuf::Arena* arena,
    const AskLogin& from)
    : ::google::protobuf::Message(arena) {
  AskLogin* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, platform_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, platform_),
           offsetof(Impl_, msgid_) -
               offsetof(Impl_, platform_) +
               sizeof(Impl_::msgid_));

  // @@protoc_insertion_point(copy_constructor:GCToLS.AskLogin)
}
inline PROTOBUF_NDEBUG_INLINE AskLogin::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        uin_(arena),
        sessionid_(arena),
        msgid_{static_cast< ::GCToLS::MsgID >(40961)} {}

inline void AskLogin::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.platform_ = {};
}
AskLogin::~AskLogin() {
  // @@protoc_insertion_point(destructor:GCToLS.AskLogin)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void AskLogin::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.uin_.Destroy();
  _impl_.sessionid_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
AskLogin::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(AskLogin, _impl_._cached_size_),
              false,
          },
          &AskLogin::MergeImpl,
          &AskLogin::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void AskLogin::Clear() {
// @@protoc_insertion_point(message_clear_start:GCToLS.AskLogin)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _impl_.uin_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      _impl_.sessionid_.ClearNonDefaultToEmpty();
    }
  }
  if (cached_has_bits & 0x0000000cu) {
    _impl_.platform_ = 0u;
    _impl_.msgid_ = 40961;
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* AskLogin::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 4, 1, 36, 2> AskLogin::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(AskLogin, _impl_._has_bits_),
    0, // no _extensions_
    4, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967280,  // skipmap
    offsetof(decltype(_table_), field_entries),
    4,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_AskLogin_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::GCToLS::AskLogin>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // optional string sessionid = 4;
    {::_pbi::TcParser::FastSS1,
     {34, 1, 0, PROTOBUF_FIELD_OFFSET(AskLogin, _impl_.sessionid_)}},
    // optional .GCToLS.MsgID msgid = 1 [default = eMsgToLSFromGC_AskLogin];
    {::_pbi::TcParser::FastEvS1,
     {8, 3, 0, PROTOBUF_FIELD_OFFSET(AskLogin, _impl_.msgid_)}},
    // optional uint32 platform = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(AskLogin, _impl_.platform_), 2>(),
     {16, 2, 0, PROTOBUF_FIELD_OFFSET(AskLogin, _impl_.platform_)}},
    // optional string uin = 3;
    {::_pbi::TcParser::FastSS1,
     {26, 0, 0, PROTOBUF_FIELD_OFFSET(AskLogin, _impl_.uin_)}},
  }}, {{
    65535, 65535
  }}, {{
    // optional .GCToLS.MsgID msgid = 1 [default = eMsgToLSFromGC_AskLogin];
    {PROTOBUF_FIELD_OFFSET(AskLogin, _impl_.msgid_), _Internal::kHasBitsOffset + 3, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kEnum)},
    // optional uint32 platform = 2;
    {PROTOBUF_FIELD_OFFSET(AskLogin, _impl_.platform_), _Internal::kHasBitsOffset + 2, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kUInt32)},
    // optional string uin = 3;
    {PROTOBUF_FIELD_OFFSET(AskLogin, _impl_.uin_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
    // optional string sessionid = 4;
    {PROTOBUF_FIELD_OFFSET(AskLogin, _impl_.sessionid_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
  }}, {{
    {::_pbi::FieldAuxEnumData{}, ::GCToLS::MsgID_internal_data_},
  }}, {{
    "\17\0\0\3\11\0\0\0"
    "GCToLS.AskLogin"
    "uin"
    "sessionid"
  }},
};

::uint8_t* AskLogin::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:GCToLS.AskLogin)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional .GCToLS.MsgID msgid = 1 [default = eMsgToLSFromGC_AskLogin];
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
        1, this->_internal_msgid(), target);
  }

  // optional uint32 platform = 2;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(
        2, this->_internal_platform(), target);
  }

  // optional string uin = 3;
  if (cached_has_bits & 0x00000001u) {
    const std::string& _s = this->_internal_uin();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "GCToLS.AskLogin.uin");
    target = stream->WriteStringMaybeAliased(3, _s, target);
  }

  // optional string sessionid = 4;
  if (cached_has_bits & 0x00000002u) {
    const std::string& _s = this->_internal_sessionid();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "GCToLS.AskLogin.sessionid");
    target = stream->WriteStringMaybeAliased(4, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:GCToLS.AskLogin)
  return target;
}

::size_t AskLogin::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:GCToLS.AskLogin)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    // optional string uin = 3;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_uin());
    }

    // optional string sessionid = 4;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_sessionid());
    }

    // optional uint32 platform = 2;
    if (cached_has_bits & 0x00000004u) {
      total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(
          this->_internal_platform());
    }

    // optional .GCToLS.MsgID msgid = 1 [default = eMsgToLSFromGC_AskLogin];
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
                    ::_pbi::WireFormatLite::EnumSize(this->_internal_msgid());
    }

  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void AskLogin::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<AskLogin*>(&to_msg);
  auto& from = static_cast<const AskLogin&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:GCToLS.AskLogin)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_set_uin(from._internal_uin());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_internal_set_sessionid(from._internal_sessionid());
    }
    if (cached_has_bits & 0x00000004u) {
      _this->_impl_.platform_ = from._impl_.platform_;
    }
    if (cached_has_bits & 0x00000008u) {
      _this->_impl_.msgid_ = from._impl_.msgid_;
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void AskLogin::CopyFrom(const AskLogin& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:GCToLS.AskLogin)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool AskLogin::IsInitialized() const {
  return true;
}

void AskLogin::InternalSwap(AskLogin* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.uin_, &other->_impl_.uin_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.sessionid_, &other->_impl_.sessionid_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(AskLogin, _impl_.msgid_)
      + sizeof(AskLogin::_impl_.msgid_)
      - PROTOBUF_FIELD_OFFSET(AskLogin, _impl_.platform_)>(
          reinterpret_cast<char*>(&_impl_.platform_),
          reinterpret_cast<char*>(&other->_impl_.platform_));
}

::google::protobuf::Metadata AskLogin::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_GCToLS_2eproto_getter,
                                   &descriptor_table_GCToLS_2eproto_once,
                                   file_level_metadata_GCToLS_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace GCToLS
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::std::false_type _static_init_ PROTOBUF_UNUSED =
    (::_pbi::AddDescriptors(&descriptor_table_GCToLS_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"