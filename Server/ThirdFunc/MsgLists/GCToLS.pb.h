// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GCToLS.proto
// Protobuf C++ Version: 4.26.0-dev

#ifndef GOOGLE_PROTOBUF_INCLUDED_GCToLS_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_GCToLS_2eproto_2epb_2eh

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

#define PROTOBUF_INTERNAL_EXPORT_GCToLS_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_GCToLS_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_GCToLS_2eproto;
namespace GCToLS {
class AskLogin;
struct AskLoginDefaultTypeInternal;
extern AskLoginDefaultTypeInternal _AskLogin_default_instance_;
}  // namespace GCToLS
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace GCToLS {
enum MsgID : int {
  eMsgToLSFromGC_Begin = 40960,
  eMsgToLSFromGC_AskLogin = 40961,
  eMsgToLSFromGC_End = 40970,
};

bool MsgID_IsValid(int value);
extern const uint32_t MsgID_internal_data_[];
constexpr MsgID MsgID_MIN = static_cast<MsgID>(40960);
constexpr MsgID MsgID_MAX = static_cast<MsgID>(40970);
constexpr int MsgID_ARRAYSIZE = 40970 + 1;
const ::google::protobuf::EnumDescriptor*
MsgID_descriptor();
template <typename T>
const std::string& MsgID_Name(T value) {
  static_assert(std::is_same<T, MsgID>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to MsgID_Name().");
  return MsgID_Name(static_cast<MsgID>(value));
}
template <>
inline const std::string& MsgID_Name(MsgID value) {
  return ::google::protobuf::internal::NameOfDenseEnum<MsgID_descriptor,
                                                 40960, 40970>(
      static_cast<int>(value));
}
inline bool MsgID_Parse(absl::string_view name, MsgID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MsgID>(
      MsgID_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class AskLogin final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:GCToLS.AskLogin) */ {
 public:
  inline AskLogin() : AskLogin(nullptr) {}
  ~AskLogin() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR AskLogin(
      ::google::protobuf::internal::ConstantInitialized);

  inline AskLogin(const AskLogin& from) : AskLogin(nullptr, from) {}
  inline AskLogin(AskLogin&& from) noexcept
      : AskLogin(nullptr, std::move(from)) {}
  inline AskLogin& operator=(const AskLogin& from) {
    CopyFrom(from);
    return *this;
  }
  inline AskLogin& operator=(AskLogin&& from) noexcept {
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
  static const AskLogin& default_instance() {
    return *internal_default_instance();
  }
  static inline const AskLogin* internal_default_instance() {
    return reinterpret_cast<const AskLogin*>(
        &_AskLogin_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(AskLogin& a, AskLogin& b) { a.Swap(&b); }
  inline void Swap(AskLogin* other) {
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
  void UnsafeArenaSwap(AskLogin* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  AskLogin* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<AskLogin>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const AskLogin& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const AskLogin& from) { AskLogin::MergeImpl(*this, from); }

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
  void InternalSwap(AskLogin* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "GCToLS.AskLogin"; }

 protected:
  explicit AskLogin(::google::protobuf::Arena* arena);
  AskLogin(::google::protobuf::Arena* arena, const AskLogin& from);
  AskLogin(::google::protobuf::Arena* arena, AskLogin&& from) noexcept
      : AskLogin(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kUinFieldNumber = 3,
    kSessionidFieldNumber = 4,
    kPlatformFieldNumber = 2,
    kMsgidFieldNumber = 1,
  };
  // optional string uin = 3;
  bool has_uin() const;
  void clear_uin() ;
  const std::string& uin() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_uin(Arg_&& arg, Args_... args);
  std::string* mutable_uin();
  PROTOBUF_NODISCARD std::string* release_uin();
  void set_allocated_uin(std::string* value);

  private:
  const std::string& _internal_uin() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_uin(
      const std::string& value);
  std::string* _internal_mutable_uin();

  public:
  // optional string sessionid = 4;
  bool has_sessionid() const;
  void clear_sessionid() ;
  const std::string& sessionid() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_sessionid(Arg_&& arg, Args_... args);
  std::string* mutable_sessionid();
  PROTOBUF_NODISCARD std::string* release_sessionid();
  void set_allocated_sessionid(std::string* value);

  private:
  const std::string& _internal_sessionid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_sessionid(
      const std::string& value);
  std::string* _internal_mutable_sessionid();

  public:
  // optional uint32 platform = 2;
  bool has_platform() const;
  void clear_platform() ;
  ::uint32_t platform() const;
  void set_platform(::uint32_t value);

  private:
  ::uint32_t _internal_platform() const;
  void _internal_set_platform(::uint32_t value);

  public:
  // optional .GCToLS.MsgID msgid = 1 [default = eMsgToLSFromGC_AskLogin];
  bool has_msgid() const;
  void clear_msgid() ;
  ::GCToLS::MsgID msgid() const;
  void set_msgid(::GCToLS::MsgID value);

  private:
  ::GCToLS::MsgID _internal_msgid() const;
  void _internal_set_msgid(::GCToLS::MsgID value);

  public:
  // @@protoc_insertion_point(class_scope:GCToLS.AskLogin)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 4, 1,
      36, 2>
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
    ::google::protobuf::internal::ArenaStringPtr uin_;
    ::google::protobuf::internal::ArenaStringPtr sessionid_;
    ::uint32_t platform_;
    int msgid_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_GCToLS_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// AskLogin

// optional .GCToLS.MsgID msgid = 1 [default = eMsgToLSFromGC_AskLogin];
inline bool AskLogin::has_msgid() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline void AskLogin::clear_msgid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.msgid_ = 40961;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline ::GCToLS::MsgID AskLogin::msgid() const {
  // @@protoc_insertion_point(field_get:GCToLS.AskLogin.msgid)
  return _internal_msgid();
}
inline void AskLogin::set_msgid(::GCToLS::MsgID value) {
  _internal_set_msgid(value);
  _impl_._has_bits_[0] |= 0x00000008u;
  // @@protoc_insertion_point(field_set:GCToLS.AskLogin.msgid)
}
inline ::GCToLS::MsgID AskLogin::_internal_msgid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return static_cast<::GCToLS::MsgID>(_impl_.msgid_);
}
inline void AskLogin::_internal_set_msgid(::GCToLS::MsgID value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  assert(::GCToLS::MsgID_IsValid(value));
  _impl_.msgid_ = value;
}

// optional uint32 platform = 2;
inline bool AskLogin::has_platform() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void AskLogin::clear_platform() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.platform_ = 0u;
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline ::uint32_t AskLogin::platform() const {
  // @@protoc_insertion_point(field_get:GCToLS.AskLogin.platform)
  return _internal_platform();
}
inline void AskLogin::set_platform(::uint32_t value) {
  _internal_set_platform(value);
  _impl_._has_bits_[0] |= 0x00000004u;
  // @@protoc_insertion_point(field_set:GCToLS.AskLogin.platform)
}
inline ::uint32_t AskLogin::_internal_platform() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.platform_;
}
inline void AskLogin::_internal_set_platform(::uint32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.platform_ = value;
}

// optional string uin = 3;
inline bool AskLogin::has_uin() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void AskLogin::clear_uin() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.uin_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& AskLogin::uin() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:GCToLS.AskLogin.uin)
  return _internal_uin();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void AskLogin::set_uin(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.uin_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:GCToLS.AskLogin.uin)
}
inline std::string* AskLogin::mutable_uin() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_uin();
  // @@protoc_insertion_point(field_mutable:GCToLS.AskLogin.uin)
  return _s;
}
inline const std::string& AskLogin::_internal_uin() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.uin_.Get();
}
inline void AskLogin::_internal_set_uin(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.uin_.Set(value, GetArena());
}
inline std::string* AskLogin::_internal_mutable_uin() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.uin_.Mutable( GetArena());
}
inline std::string* AskLogin::release_uin() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:GCToLS.AskLogin.uin)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* released = _impl_.uin_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.uin_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void AskLogin::set_allocated_uin(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.uin_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.uin_.IsDefault()) {
          _impl_.uin_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:GCToLS.AskLogin.uin)
}

// optional string sessionid = 4;
inline bool AskLogin::has_sessionid() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void AskLogin::clear_sessionid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.sessionid_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& AskLogin::sessionid() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:GCToLS.AskLogin.sessionid)
  return _internal_sessionid();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void AskLogin::set_sessionid(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.sessionid_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:GCToLS.AskLogin.sessionid)
}
inline std::string* AskLogin::mutable_sessionid() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_sessionid();
  // @@protoc_insertion_point(field_mutable:GCToLS.AskLogin.sessionid)
  return _s;
}
inline const std::string& AskLogin::_internal_sessionid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.sessionid_.Get();
}
inline void AskLogin::_internal_set_sessionid(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.sessionid_.Set(value, GetArena());
}
inline std::string* AskLogin::_internal_mutable_sessionid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.sessionid_.Mutable( GetArena());
}
inline std::string* AskLogin::release_sessionid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:GCToLS.AskLogin.sessionid)
  if ((_impl_._has_bits_[0] & 0x00000002u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000002u;
  auto* released = _impl_.sessionid_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.sessionid_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void AskLogin::set_allocated_sessionid(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.sessionid_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.sessionid_.IsDefault()) {
          _impl_.sessionid_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:GCToLS.AskLogin.sessionid)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace GCToLS


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::GCToLS::MsgID> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::GCToLS::MsgID>() {
  return ::GCToLS::MsgID_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_GCToLS_2eproto_2epb_2eh