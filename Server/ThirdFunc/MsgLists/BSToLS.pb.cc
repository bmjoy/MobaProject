// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BSToLS.proto
// Protobuf C++ Version: 4.26.0-dev

#include "BSToLS.pb.h"

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
namespace BSToLS {

inline constexpr AskRegister::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        msgid_{static_cast< ::BSToLS::MsgID >(40961)} {}

template <typename>
PROTOBUF_CONSTEXPR AskRegister::AskRegister(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct AskRegisterDefaultTypeInternal {
  PROTOBUF_CONSTEXPR AskRegisterDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~AskRegisterDefaultTypeInternal() {}
  union {
    AskRegister _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 AskRegisterDefaultTypeInternal _AskRegister_default_instance_;
}  // namespace BSToLS
static ::_pb::Metadata file_level_metadata_BSToLS_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_BSToLS_2eproto[1];
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_BSToLS_2eproto = nullptr;
const ::uint32_t
    TableStruct_BSToLS_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::BSToLS::AskRegister, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::BSToLS::AskRegister, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::BSToLS::AskRegister, _impl_.msgid_),
        0,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 9, -1, sizeof(::BSToLS::AskRegister)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::BSToLS::_AskRegister_default_instance_._instance,
};
const char descriptor_table_protodef_BSToLS_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\014BSToLS.proto\022\006BSToLS\"G\n\013AskRegister\0228\n"
    "\005msgid\030\001 \001(\0162\r.BSToLS.MsgID:\032eMsgToLSFro"
    "mBS_AskRegister*\211\001\n\005MsgID\022\032\n\024eMsgToLSFro"
    "mBS_Begin\020\200\300\002\022 \n\032eMsgToLSFromBS_AskRegis"
    "ter\020\201\300\002\022(\n\"eMsgToLSFromBC_OneClinetLogin"
    "Check\020\202\300\002\022\030\n\022eMsgToLSFromBS_End\020\250\300\002"
};
static ::absl::once_flag descriptor_table_BSToLS_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_BSToLS_2eproto = {
    false,
    false,
    235,
    descriptor_table_protodef_BSToLS_2eproto,
    "BSToLS.proto",
    &descriptor_table_BSToLS_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_BSToLS_2eproto::offsets,
    file_level_metadata_BSToLS_2eproto,
    file_level_enum_descriptors_BSToLS_2eproto,
    file_level_service_descriptors_BSToLS_2eproto,
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
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_BSToLS_2eproto_getter() {
  return &descriptor_table_BSToLS_2eproto;
}
namespace BSToLS {
const ::google::protobuf::EnumDescriptor* MsgID_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_BSToLS_2eproto);
  return file_level_enum_descriptors_BSToLS_2eproto[0];
}
PROTOBUF_CONSTINIT const uint32_t MsgID_internal_data_[] = {
    0u, 262144u, 40962u, 40961u, 41000u, 40960u, };
bool MsgID_IsValid(int value) {
  return ::_pbi::ValidateEnum(value, MsgID_internal_data_);
}
// ===================================================================

class AskRegister::_Internal {
 public:
  using HasBits = decltype(std::declval<AskRegister>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(AskRegister, _impl_._has_bits_);
};

AskRegister::AskRegister(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:BSToLS.AskRegister)
}
AskRegister::AskRegister(
    ::google::protobuf::Arena* arena, const AskRegister& from)
    : AskRegister(arena) {
  MergeFrom(from);
}
inline PROTOBUF_NDEBUG_INLINE AskRegister::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        msgid_{static_cast< ::BSToLS::MsgID >(40961)} {}

inline void AskRegister::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
AskRegister::~AskRegister() {
  // @@protoc_insertion_point(destructor:BSToLS.AskRegister)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void AskRegister::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
AskRegister::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(AskRegister, _impl_._cached_size_),
              false,
          },
          &AskRegister::MergeImpl,
          &AskRegister::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void AskRegister::Clear() {
// @@protoc_insertion_point(message_clear_start:BSToLS.AskRegister)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.msgid_ = 40961;
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* AskRegister::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 1, 0, 2> AskRegister::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(AskRegister, _impl_._has_bits_),
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_AskRegister_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::BSToLS::AskRegister>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // optional .BSToLS.MsgID msgid = 1 [default = eMsgToLSFromBS_AskRegister];
    {::_pbi::TcParser::FastEvS1,
     {8, 0, 0, PROTOBUF_FIELD_OFFSET(AskRegister, _impl_.msgid_)}},
  }}, {{
    65535, 65535
  }}, {{
    // optional .BSToLS.MsgID msgid = 1 [default = eMsgToLSFromBS_AskRegister];
    {PROTOBUF_FIELD_OFFSET(AskRegister, _impl_.msgid_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kEnum)},
  }}, {{
    {::_pbi::FieldAuxEnumData{}, ::BSToLS::MsgID_internal_data_},
  }}, {{
  }},
};

::uint8_t* AskRegister::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:BSToLS.AskRegister)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional .BSToLS.MsgID msgid = 1 [default = eMsgToLSFromBS_AskRegister];
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
        1, this->_internal_msgid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:BSToLS.AskRegister)
  return target;
}

::size_t AskRegister::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:BSToLS.AskRegister)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional .BSToLS.MsgID msgid = 1 [default = eMsgToLSFromBS_AskRegister];
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
                  ::_pbi::WireFormatLite::EnumSize(this->_internal_msgid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void AskRegister::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<AskRegister*>(&to_msg);
  auto& from = static_cast<const AskRegister&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:BSToLS.AskRegister)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _this->_impl_.msgid_ = from._impl_.msgid_;
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void AskRegister::CopyFrom(const AskRegister& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:BSToLS.AskRegister)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool AskRegister::IsInitialized() const {
  return true;
}

void AskRegister::InternalSwap(AskRegister* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  swap(_impl_.msgid_, other->_impl_.msgid_);
}

::google::protobuf::Metadata AskRegister::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_BSToLS_2eproto_getter,
                                   &descriptor_table_BSToLS_2eproto_once,
                                   file_level_metadata_BSToLS_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace BSToLS
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::std::false_type _static_init_ PROTOBUF_UNUSED =
    (::_pbi::AddDescriptors(&descriptor_table_BSToLS_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"
