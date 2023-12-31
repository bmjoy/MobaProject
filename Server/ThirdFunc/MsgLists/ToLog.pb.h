// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ToLog.proto
// Protobuf C++ Version: 4.26.0-dev

#ifndef GOOGLE_PROTOBUF_INCLUDED_ToLog_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_ToLog_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION != 4026000
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/generated_enum_reflection.h"
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_ToLog_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_ToLog_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_ToLog_2eproto;
namespace ToLog {
class WriteLog;
struct WriteLogDefaultTypeInternal;
extern WriteLogDefaultTypeInternal _WriteLog_default_instance_;
}  // namespace ToLog
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace ToLog {
enum MsgID : int {
  eMsgToLog_Begin = 0,
  eMsgToLog_WriteLog = 1,
  eMsgToLog_End = 100,
};

bool MsgID_IsValid(int value);
extern const uint32_t MsgID_internal_data_[];
constexpr MsgID MsgID_MIN = static_cast<MsgID>(0);
constexpr MsgID MsgID_MAX = static_cast<MsgID>(100);
constexpr int MsgID_ARRAYSIZE = 100 + 1;
const ::google::protobuf::EnumDescriptor*
MsgID_descriptor();
template <typename T>
const std::string& MsgID_Name(T value) {
  static_assert(std::is_same<T, MsgID>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to MsgID_Name().");
  return ::google::protobuf::internal::NameOfEnum(MsgID_descriptor(), value);
}
inline bool MsgID_Parse(absl::string_view name, MsgID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MsgID>(
      MsgID_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class WriteLog final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:ToLog.WriteLog) */ {
 public:
  inline WriteLog() : WriteLog(nullptr) {}
  ~WriteLog() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR WriteLog(
      ::google::protobuf::internal::ConstantInitialized);

  inline WriteLog(const WriteLog& from) : WriteLog(nullptr, from) {}
  inline WriteLog(WriteLog&& from) noexcept
      : WriteLog(nullptr, std::move(from)) {}
  inline WriteLog& operator=(const WriteLog& from) {
    CopyFrom(from);
    return *this;
  }
  inline WriteLog& operator=(WriteLog&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const WriteLog& default_instance() {
    return *internal_default_instance();
  }
  static inline const WriteLog* internal_default_instance() {
    return reinterpret_cast<const WriteLog*>(
        &_WriteLog_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(WriteLog& a, WriteLog& b) { a.Swap(&b); }
  inline void Swap(WriteLog* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(WriteLog* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  WriteLog* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<WriteLog>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const WriteLog& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const WriteLog& from) { WriteLog::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(WriteLog* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "ToLog.WriteLog"; }

 protected:
  explicit WriteLog(::google::protobuf::Arena* arena);
  WriteLog(::google::protobuf::Arena* arena, const WriteLog& from);
  WriteLog(::google::protobuf::Arena* arena, WriteLog&& from) noexcept
      : WriteLog(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kLogStrFieldNumber = 3,
    kLogTypeFieldNumber = 2,
    kMsgidFieldNumber = 1,
  };
  // optional string log_str = 3;
  bool has_log_str() const;
  void clear_log_str() ;
  const std::string& log_str() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_log_str(Arg_&& arg, Args_... args);
  std::string* mutable_log_str();
  PROTOBUF_NODISCARD std::string* release_log_str();
  void set_allocated_log_str(std::string* value);

  private:
  const std::string& _internal_log_str() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_log_str(
      const std::string& value);
  std::string* _internal_mutable_log_str();

  public:
  // optional int32 log_type = 2;
  bool has_log_type() const;
  void clear_log_type() ;
  ::int32_t log_type() const;
  void set_log_type(::int32_t value);

  private:
  ::int32_t _internal_log_type() const;
  void _internal_set_log_type(::int32_t value);

  public:
  // optional .ToLog.MsgID msgid = 1 [default = eMsgToLog_WriteLog];
  bool has_msgid() const;
  void clear_msgid() ;
  ::ToLog::MsgID msgid() const;
  void set_msgid(::ToLog::MsgID value);

  private:
  ::ToLog::MsgID _internal_msgid() const;
  void _internal_set_msgid(::ToLog::MsgID value);

  public:
  // @@protoc_insertion_point(class_scope:ToLog.WriteLog)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 3, 1,
      30, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::protobuf::internal::ArenaStringPtr log_str_;
    ::int32_t log_type_;
    int msgid_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ToLog_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// WriteLog

// optional .ToLog.MsgID msgid = 1 [default = eMsgToLog_WriteLog];
inline bool WriteLog::has_msgid() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void WriteLog::clear_msgid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.msgid_ = 1;
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline ::ToLog::MsgID WriteLog::msgid() const {
  // @@protoc_insertion_point(field_get:ToLog.WriteLog.msgid)
  return _internal_msgid();
}
inline void WriteLog::set_msgid(::ToLog::MsgID value) {
  _internal_set_msgid(value);
  _impl_._has_bits_[0] |= 0x00000004u;
  // @@protoc_insertion_point(field_set:ToLog.WriteLog.msgid)
}
inline ::ToLog::MsgID WriteLog::_internal_msgid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return static_cast<::ToLog::MsgID>(_impl_.msgid_);
}
inline void WriteLog::_internal_set_msgid(::ToLog::MsgID value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  assert(::ToLog::MsgID_IsValid(value));
  _impl_.msgid_ = value;
}

// optional int32 log_type = 2;
inline bool WriteLog::has_log_type() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void WriteLog::clear_log_type() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.log_type_ = 0;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline ::int32_t WriteLog::log_type() const {
  // @@protoc_insertion_point(field_get:ToLog.WriteLog.log_type)
  return _internal_log_type();
}
inline void WriteLog::set_log_type(::int32_t value) {
  _internal_set_log_type(value);
  _impl_._has_bits_[0] |= 0x00000002u;
  // @@protoc_insertion_point(field_set:ToLog.WriteLog.log_type)
}
inline ::int32_t WriteLog::_internal_log_type() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.log_type_;
}
inline void WriteLog::_internal_set_log_type(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.log_type_ = value;
}

// optional string log_str = 3;
inline bool WriteLog::has_log_str() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void WriteLog::clear_log_str() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.log_str_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& WriteLog::log_str() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:ToLog.WriteLog.log_str)
  return _internal_log_str();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void WriteLog::set_log_str(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.log_str_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:ToLog.WriteLog.log_str)
}
inline std::string* WriteLog::mutable_log_str() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_log_str();
  // @@protoc_insertion_point(field_mutable:ToLog.WriteLog.log_str)
  return _s;
}
inline const std::string& WriteLog::_internal_log_str() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.log_str_.Get();
}
inline void WriteLog::_internal_set_log_str(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.log_str_.Set(value, GetArena());
}
inline std::string* WriteLog::_internal_mutable_log_str() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.log_str_.Mutable( GetArena());
}
inline std::string* WriteLog::release_log_str() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:ToLog.WriteLog.log_str)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* released = _impl_.log_str_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.log_str_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void WriteLog::set_allocated_log_str(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.log_str_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.log_str_.IsDefault()) {
          _impl_.log_str_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:ToLog.WriteLog.log_str)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace ToLog


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::ToLog::MsgID> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::ToLog::MsgID>() {
  return ::ToLog::MsgID_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_ToLog_2eproto_2epb_2eh
