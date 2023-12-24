// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: LSToSDK.proto
// Protobuf C++ Version: 4.26.0-dev

#include "LSToSDK.pb.h"

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
namespace LSToSDK {

inline constexpr UserLogin91::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        logininfo_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        gcid_{0},
        mgsid_{static_cast< ::LSToSDK::MsgID >(1)} {}

template <typename>
PROTOBUF_CONSTEXPR UserLogin91::UserLogin91(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct UserLogin91DefaultTypeInternal {
  PROTOBUF_CONSTEXPR UserLogin91DefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~UserLogin91DefaultTypeInternal() {}
  union {
    UserLogin91 _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 UserLogin91DefaultTypeInternal _UserLogin91_default_instance_;
}  // namespace LSToSDK
static ::_pb::Metadata file_level_metadata_LSToSDK_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_LSToSDK_2eproto[1];
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_LSToSDK_2eproto = nullptr;
const ::uint32_t
    TableStruct_LSToSDK_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::LSToSDK::UserLogin91, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::LSToSDK::UserLogin91, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::LSToSDK::UserLogin91, _impl_.mgsid_),
        PROTOBUF_FIELD_OFFSET(::LSToSDK::UserLogin91, _impl_.logininfo_),
        PROTOBUF_FIELD_OFFSET(::LSToSDK::UserLogin91, _impl_.gcid_),
        2,
        0,
        1,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 11, -1, sizeof(::LSToSDK::UserLogin91)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::LSToSDK::_UserLogin91_default_instance_._instance,
};
const char descriptor_table_protodef_LSToSDK_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\rLSToSDK.proto\022\007LSToSDK\"i\n\013UserLogin91\022"
    "9\n\005mgsid\030\001 \001(\0162\016.LSToSDK.MsgID:\032eMsgToGC"
    "FromBS_91UserLogin\022\021\n\tlogininfo\030\002 \001(\t\022\014\n"
    "\004gcid\030\004 \001(\005*\'\n\005MsgID\022\036\n\032eMsgToGCFromBS_9"
    "1UserLogin\020\001"
};
static ::absl::once_flag descriptor_table_LSToSDK_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_LSToSDK_2eproto = {
    false,
    false,
    172,
    descriptor_table_protodef_LSToSDK_2eproto,
    "LSToSDK.proto",
    &descriptor_table_LSToSDK_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_LSToSDK_2eproto::offsets,
    file_level_metadata_LSToSDK_2eproto,
    file_level_enum_descriptors_LSToSDK_2eproto,
    file_level_service_descriptors_LSToSDK_2eproto,
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
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_LSToSDK_2eproto_getter() {
  return &descriptor_table_LSToSDK_2eproto;
}
namespace LSToSDK {
const ::google::protobuf::EnumDescriptor* MsgID_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_LSToSDK_2eproto);
  return file_level_enum_descriptors_LSToSDK_2eproto[0];
}
PROTOBUF_CONSTINIT const uint32_t MsgID_internal_data_[] = {
    65537u, 0u, };
bool MsgID_IsValid(int value) {
  return 1 <= value && value <= 1;
}
// ===================================================================

class UserLogin91::_Internal {
 public:
  using HasBits = decltype(std::declval<UserLogin91>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(UserLogin91, _impl_._has_bits_);
};

UserLogin91::UserLogin91(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:LSToSDK.UserLogin91)
}
inline PROTOBUF_NDEBUG_INLINE UserLogin91::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        logininfo_(arena, from.logininfo_) {}

UserLogin91::UserLogin91(
    ::google::protobuf::Arena* arena,
    const UserLogin91& from)
    : ::google::protobuf::Message(arena) {
  UserLogin91* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, gcid_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, gcid_),
           offsetof(Impl_, mgsid_) -
               offsetof(Impl_, gcid_) +
               sizeof(Impl_::mgsid_));

  // @@protoc_insertion_point(copy_constructor:LSToSDK.UserLogin91)
}
inline PROTOBUF_NDEBUG_INLINE UserLogin91::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        logininfo_(arena),
        mgsid_{static_cast< ::LSToSDK::MsgID >(1)} {}

inline void UserLogin91::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.gcid_ = {};
}
UserLogin91::~UserLogin91() {
  // @@protoc_insertion_point(destructor:LSToSDK.UserLogin91)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void UserLogin91::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.logininfo_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
UserLogin91::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(UserLogin91, _impl_._cached_size_),
              false,
          },
          &UserLogin91::MergeImpl,
          &UserLogin91::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void UserLogin91::Clear() {
// @@protoc_insertion_point(message_clear_start:LSToSDK.UserLogin91)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _impl_.logininfo_.ClearNonDefaultToEmpty();
  }
  if (cached_has_bits & 0x00000006u) {
    _impl_.gcid_ = 0;
    _impl_.mgsid_ = 1;
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* UserLogin91::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 3, 1, 37, 2> UserLogin91::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(UserLogin91, _impl_._has_bits_),
    0, // no _extensions_
    4, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967284,  // skipmap
    offsetof(decltype(_table_), field_entries),
    3,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_UserLogin91_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::LSToSDK::UserLogin91>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // optional int32 gcid = 4;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(UserLogin91, _impl_.gcid_), 1>(),
     {32, 1, 0, PROTOBUF_FIELD_OFFSET(UserLogin91, _impl_.gcid_)}},
    // optional .LSToSDK.MsgID mgsid = 1 [default = eMsgToGCFromBS_91UserLogin];
    {::_pbi::TcParser::FastEr1S1,
     {8, 2, 1, PROTOBUF_FIELD_OFFSET(UserLogin91, _impl_.mgsid_)}},
    // optional string logininfo = 2;
    {::_pbi::TcParser::FastSS1,
     {18, 0, 0, PROTOBUF_FIELD_OFFSET(UserLogin91, _impl_.logininfo_)}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // optional .LSToSDK.MsgID mgsid = 1 [default = eMsgToGCFromBS_91UserLogin];
    {PROTOBUF_FIELD_OFFSET(UserLogin91, _impl_.mgsid_), _Internal::kHasBitsOffset + 2, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kEnumRange)},
    // optional string logininfo = 2;
    {PROTOBUF_FIELD_OFFSET(UserLogin91, _impl_.logininfo_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
    // optional int32 gcid = 4;
    {PROTOBUF_FIELD_OFFSET(UserLogin91, _impl_.gcid_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
  }}, {{
    {1, 1},
  }}, {{
    "\23\0\11\0\0\0\0\0"
    "LSToSDK.UserLogin91"
    "logininfo"
  }},
};

::uint8_t* UserLogin91::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:LSToSDK.UserLogin91)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional .LSToSDK.MsgID mgsid = 1 [default = eMsgToGCFromBS_91UserLogin];
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
        1, this->_internal_mgsid(), target);
  }

  // optional string logininfo = 2;
  if (cached_has_bits & 0x00000001u) {
    const std::string& _s = this->_internal_logininfo();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "LSToSDK.UserLogin91.logininfo");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  // optional int32 gcid = 4;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<4>(
            stream, this->_internal_gcid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:LSToSDK.UserLogin91)
  return target;
}

::size_t UserLogin91::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:LSToSDK.UserLogin91)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    // optional string logininfo = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_logininfo());
    }

    // optional int32 gcid = 4;
    if (cached_has_bits & 0x00000002u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_gcid());
    }

    // optional .LSToSDK.MsgID mgsid = 1 [default = eMsgToGCFromBS_91UserLogin];
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
                    ::_pbi::WireFormatLite::EnumSize(this->_internal_mgsid());
    }

  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void UserLogin91::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<UserLogin91*>(&to_msg);
  auto& from = static_cast<const UserLogin91&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:LSToSDK.UserLogin91)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_set_logininfo(from._internal_logininfo());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_impl_.gcid_ = from._impl_.gcid_;
    }
    if (cached_has_bits & 0x00000004u) {
      _this->_impl_.mgsid_ = from._impl_.mgsid_;
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void UserLogin91::CopyFrom(const UserLogin91& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:LSToSDK.UserLogin91)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool UserLogin91::IsInitialized() const {
  return true;
}

void UserLogin91::InternalSwap(UserLogin91* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.logininfo_, &other->_impl_.logininfo_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(UserLogin91, _impl_.mgsid_)
      + sizeof(UserLogin91::_impl_.mgsid_)
      - PROTOBUF_FIELD_OFFSET(UserLogin91, _impl_.gcid_)>(
          reinterpret_cast<char*>(&_impl_.gcid_),
          reinterpret_cast<char*>(&other->_impl_.gcid_));
}

::google::protobuf::Metadata UserLogin91::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_LSToSDK_2eproto_getter,
                                   &descriptor_table_LSToSDK_2eproto_once,
                                   file_level_metadata_LSToSDK_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace LSToSDK
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::std::false_type _static_init_ PROTOBUF_UNUSED =
    (::_pbi::AddDescriptors(&descriptor_table_LSToSDK_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"