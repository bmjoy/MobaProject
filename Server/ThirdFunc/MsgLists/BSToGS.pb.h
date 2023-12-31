// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BSToGS.proto
// Protobuf C++ Version: 4.26.0-dev

#ifndef GOOGLE_PROTOBUF_INCLUDED_BSToGS_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_BSToGS_2eproto_2epb_2eh

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

#define PROTOBUF_INTERNAL_EXPORT_BSToGS_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_BSToGS_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_BSToGS_2eproto;
namespace BSToGS {
class AskRegister;
struct AskRegisterDefaultTypeInternal;
extern AskRegisterDefaultTypeInternal _AskRegister_default_instance_;
class OneUserLoginToken;
struct OneUserLoginTokenDefaultTypeInternal;
extern OneUserLoginTokenDefaultTypeInternal _OneUserLoginToken_default_instance_;
}  // namespace BSToGS
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace BSToGS {
enum MsgID : int {
  eMsgToGSFromBS_Begin = 24576,
  eMsgToGSFromBS_AskRegisterRet = 24577,
  eMsgToGSFromBS_OneUserLoginToken = 24578,
  eMsgToGSFromBS_End = 25000,
};

bool MsgID_IsValid(int value);
extern const uint32_t MsgID_internal_data_[];
constexpr MsgID MsgID_MIN = static_cast<MsgID>(24576);
constexpr MsgID MsgID_MAX = static_cast<MsgID>(25000);
constexpr int MsgID_ARRAYSIZE = 25000 + 1;
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

class OneUserLoginToken final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:BSToGS.OneUserLoginToken) */ {
 public:
  inline OneUserLoginToken() : OneUserLoginToken(nullptr) {}
  ~OneUserLoginToken() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR OneUserLoginToken(
      ::google::protobuf::internal::ConstantInitialized);

  inline OneUserLoginToken(const OneUserLoginToken& from) : OneUserLoginToken(nullptr, from) {}
  inline OneUserLoginToken(OneUserLoginToken&& from) noexcept
      : OneUserLoginToken(nullptr, std::move(from)) {}
  inline OneUserLoginToken& operator=(const OneUserLoginToken& from) {
    CopyFrom(from);
    return *this;
  }
  inline OneUserLoginToken& operator=(OneUserLoginToken&& from) noexcept {
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
  static const OneUserLoginToken& default_instance() {
    return *internal_default_instance();
  }
  static inline const OneUserLoginToken* internal_default_instance() {
    return reinterpret_cast<const OneUserLoginToken*>(
        &_OneUserLoginToken_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(OneUserLoginToken& a, OneUserLoginToken& b) { a.Swap(&b); }
  inline void Swap(OneUserLoginToken* other) {
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
  void UnsafeArenaSwap(OneUserLoginToken* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  OneUserLoginToken* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<OneUserLoginToken>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const OneUserLoginToken& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const OneUserLoginToken& from) { OneUserLoginToken::MergeImpl(*this, from); }

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
  void InternalSwap(OneUserLoginToken* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "BSToGS.OneUserLoginToken"; }

 protected:
  explicit OneUserLoginToken(::google::protobuf::Arena* arena);
  OneUserLoginToken(::google::protobuf::Arena* arena, const OneUserLoginToken& from);
  OneUserLoginToken(::google::protobuf::Arena* arena, OneUserLoginToken&& from) noexcept
      : OneUserLoginToken(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kTokenFieldNumber = 3,
    kUserNameFieldNumber = 4,
    kIpFieldNumber = 6,
    kGateclientFieldNumber = 2,
    kPortFieldNumber = 5,
    kMsgidFieldNumber = 1,
  };
  // optional string token = 3;
  bool has_token() const;
  void clear_token() ;
  const std::string& token() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_token(Arg_&& arg, Args_... args);
  std::string* mutable_token();
  PROTOBUF_NODISCARD std::string* release_token();
  void set_allocated_token(std::string* value);

  private:
  const std::string& _internal_token() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_token(
      const std::string& value);
  std::string* _internal_mutable_token();

  public:
  // optional string user_name = 4;
  bool has_user_name() const;
  void clear_user_name() ;
  const std::string& user_name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_user_name(Arg_&& arg, Args_... args);
  std::string* mutable_user_name();
  PROTOBUF_NODISCARD std::string* release_user_name();
  void set_allocated_user_name(std::string* value);

  private:
  const std::string& _internal_user_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_user_name(
      const std::string& value);
  std::string* _internal_mutable_user_name();

  public:
  // optional string ip = 6;
  bool has_ip() const;
  void clear_ip() ;
  const std::string& ip() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_ip(Arg_&& arg, Args_... args);
  std::string* mutable_ip();
  PROTOBUF_NODISCARD std::string* release_ip();
  void set_allocated_ip(std::string* value);

  private:
  const std::string& _internal_ip() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_ip(
      const std::string& value);
  std::string* _internal_mutable_ip();

  public:
  // optional int32 gateclient = 2;
  bool has_gateclient() const;
  void clear_gateclient() ;
  ::int32_t gateclient() const;
  void set_gateclient(::int32_t value);

  private:
  ::int32_t _internal_gateclient() const;
  void _internal_set_gateclient(::int32_t value);

  public:
  // optional int32 port = 5;
  bool has_port() const;
  void clear_port() ;
  ::int32_t port() const;
  void set_port(::int32_t value);

  private:
  ::int32_t _internal_port() const;
  void _internal_set_port(::int32_t value);

  public:
  // optional .BSToGS.MsgID msgid = 1 [default = eMsgToGSFromBS_OneUserLoginToken];
  bool has_msgid() const;
  void clear_msgid() ;
  ::BSToGS::MsgID msgid() const;
  void set_msgid(::BSToGS::MsgID value);

  private:
  ::BSToGS::MsgID _internal_msgid() const;
  void _internal_set_msgid(::BSToGS::MsgID value);

  public:
  // @@protoc_insertion_point(class_scope:BSToGS.OneUserLoginToken)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      3, 6, 1,
      49, 2>
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
    ::google::protobuf::internal::ArenaStringPtr token_;
    ::google::protobuf::internal::ArenaStringPtr user_name_;
    ::google::protobuf::internal::ArenaStringPtr ip_;
    ::int32_t gateclient_;
    ::int32_t port_;
    int msgid_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_BSToGS_2eproto;
};
// -------------------------------------------------------------------

class AskRegister final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:BSToGS.AskRegister) */ {
 public:
  inline AskRegister() : AskRegister(nullptr) {}
  ~AskRegister() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR AskRegister(
      ::google::protobuf::internal::ConstantInitialized);

  inline AskRegister(const AskRegister& from) : AskRegister(nullptr, from) {}
  inline AskRegister(AskRegister&& from) noexcept
      : AskRegister(nullptr, std::move(from)) {}
  inline AskRegister& operator=(const AskRegister& from) {
    CopyFrom(from);
    return *this;
  }
  inline AskRegister& operator=(AskRegister&& from) noexcept {
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
  static const AskRegister& default_instance() {
    return *internal_default_instance();
  }
  static inline const AskRegister* internal_default_instance() {
    return reinterpret_cast<const AskRegister*>(
        &_AskRegister_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(AskRegister& a, AskRegister& b) { a.Swap(&b); }
  inline void Swap(AskRegister* other) {
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
  void UnsafeArenaSwap(AskRegister* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  AskRegister* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<AskRegister>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const AskRegister& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const AskRegister& from) { AskRegister::MergeImpl(*this, from); }

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
  void InternalSwap(AskRegister* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "BSToGS.AskRegister"; }

 protected:
  explicit AskRegister(::google::protobuf::Arena* arena);
  AskRegister(::google::protobuf::Arena* arena, const AskRegister& from);
  AskRegister(::google::protobuf::Arena* arena, AskRegister&& from) noexcept
      : AskRegister(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kGsidFieldNumber = 2,
    kPortFieldNumber = 3,
    kMgsidFieldNumber = 1,
  };
  // optional int32 gsid = 2;
  bool has_gsid() const;
  void clear_gsid() ;
  ::int32_t gsid() const;
  void set_gsid(::int32_t value);

  private:
  ::int32_t _internal_gsid() const;
  void _internal_set_gsid(::int32_t value);

  public:
  // optional int32 port = 3;
  bool has_port() const;
  void clear_port() ;
  ::int32_t port() const;
  void set_port(::int32_t value);

  private:
  ::int32_t _internal_port() const;
  void _internal_set_port(::int32_t value);

  public:
  // optional .BSToGS.MsgID mgsid = 1 [default = eMsgToGSFromBS_AskRegisterRet];
  bool has_mgsid() const;
  void clear_mgsid() ;
  ::BSToGS::MsgID mgsid() const;
  void set_mgsid(::BSToGS::MsgID value);

  private:
  ::BSToGS::MsgID _internal_mgsid() const;
  void _internal_set_mgsid(::BSToGS::MsgID value);

  public:
  // @@protoc_insertion_point(class_scope:BSToGS.AskRegister)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 3, 1,
      0, 2>
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
    ::int32_t gsid_;
    ::int32_t port_;
    int mgsid_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_BSToGS_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// AskRegister

// optional .BSToGS.MsgID mgsid = 1 [default = eMsgToGSFromBS_AskRegisterRet];
inline bool AskRegister::has_mgsid() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void AskRegister::clear_mgsid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.mgsid_ = 24577;
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline ::BSToGS::MsgID AskRegister::mgsid() const {
  // @@protoc_insertion_point(field_get:BSToGS.AskRegister.mgsid)
  return _internal_mgsid();
}
inline void AskRegister::set_mgsid(::BSToGS::MsgID value) {
  _internal_set_mgsid(value);
  _impl_._has_bits_[0] |= 0x00000004u;
  // @@protoc_insertion_point(field_set:BSToGS.AskRegister.mgsid)
}
inline ::BSToGS::MsgID AskRegister::_internal_mgsid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return static_cast<::BSToGS::MsgID>(_impl_.mgsid_);
}
inline void AskRegister::_internal_set_mgsid(::BSToGS::MsgID value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  assert(::BSToGS::MsgID_IsValid(value));
  _impl_.mgsid_ = value;
}

// optional int32 gsid = 2;
inline bool AskRegister::has_gsid() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void AskRegister::clear_gsid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.gsid_ = 0;
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline ::int32_t AskRegister::gsid() const {
  // @@protoc_insertion_point(field_get:BSToGS.AskRegister.gsid)
  return _internal_gsid();
}
inline void AskRegister::set_gsid(::int32_t value) {
  _internal_set_gsid(value);
  _impl_._has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_set:BSToGS.AskRegister.gsid)
}
inline ::int32_t AskRegister::_internal_gsid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.gsid_;
}
inline void AskRegister::_internal_set_gsid(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.gsid_ = value;
}

// optional int32 port = 3;
inline bool AskRegister::has_port() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void AskRegister::clear_port() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.port_ = 0;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline ::int32_t AskRegister::port() const {
  // @@protoc_insertion_point(field_get:BSToGS.AskRegister.port)
  return _internal_port();
}
inline void AskRegister::set_port(::int32_t value) {
  _internal_set_port(value);
  _impl_._has_bits_[0] |= 0x00000002u;
  // @@protoc_insertion_point(field_set:BSToGS.AskRegister.port)
}
inline ::int32_t AskRegister::_internal_port() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.port_;
}
inline void AskRegister::_internal_set_port(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.port_ = value;
}

// -------------------------------------------------------------------

// OneUserLoginToken

// optional .BSToGS.MsgID msgid = 1 [default = eMsgToGSFromBS_OneUserLoginToken];
inline bool OneUserLoginToken::has_msgid() const {
  bool value = (_impl_._has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline void OneUserLoginToken::clear_msgid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.msgid_ = 24578;
  _impl_._has_bits_[0] &= ~0x00000020u;
}
inline ::BSToGS::MsgID OneUserLoginToken::msgid() const {
  // @@protoc_insertion_point(field_get:BSToGS.OneUserLoginToken.msgid)
  return _internal_msgid();
}
inline void OneUserLoginToken::set_msgid(::BSToGS::MsgID value) {
  _internal_set_msgid(value);
  _impl_._has_bits_[0] |= 0x00000020u;
  // @@protoc_insertion_point(field_set:BSToGS.OneUserLoginToken.msgid)
}
inline ::BSToGS::MsgID OneUserLoginToken::_internal_msgid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return static_cast<::BSToGS::MsgID>(_impl_.msgid_);
}
inline void OneUserLoginToken::_internal_set_msgid(::BSToGS::MsgID value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  assert(::BSToGS::MsgID_IsValid(value));
  _impl_.msgid_ = value;
}

// optional int32 gateclient = 2;
inline bool OneUserLoginToken::has_gateclient() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline void OneUserLoginToken::clear_gateclient() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.gateclient_ = 0;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline ::int32_t OneUserLoginToken::gateclient() const {
  // @@protoc_insertion_point(field_get:BSToGS.OneUserLoginToken.gateclient)
  return _internal_gateclient();
}
inline void OneUserLoginToken::set_gateclient(::int32_t value) {
  _internal_set_gateclient(value);
  _impl_._has_bits_[0] |= 0x00000008u;
  // @@protoc_insertion_point(field_set:BSToGS.OneUserLoginToken.gateclient)
}
inline ::int32_t OneUserLoginToken::_internal_gateclient() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.gateclient_;
}
inline void OneUserLoginToken::_internal_set_gateclient(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.gateclient_ = value;
}

// optional string token = 3;
inline bool OneUserLoginToken::has_token() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void OneUserLoginToken::clear_token() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.token_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& OneUserLoginToken::token() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:BSToGS.OneUserLoginToken.token)
  return _internal_token();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void OneUserLoginToken::set_token(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.token_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:BSToGS.OneUserLoginToken.token)
}
inline std::string* OneUserLoginToken::mutable_token() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_token();
  // @@protoc_insertion_point(field_mutable:BSToGS.OneUserLoginToken.token)
  return _s;
}
inline const std::string& OneUserLoginToken::_internal_token() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.token_.Get();
}
inline void OneUserLoginToken::_internal_set_token(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.token_.Set(value, GetArena());
}
inline std::string* OneUserLoginToken::_internal_mutable_token() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.token_.Mutable( GetArena());
}
inline std::string* OneUserLoginToken::release_token() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:BSToGS.OneUserLoginToken.token)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* released = _impl_.token_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.token_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void OneUserLoginToken::set_allocated_token(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.token_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.token_.IsDefault()) {
          _impl_.token_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:BSToGS.OneUserLoginToken.token)
}

// optional string user_name = 4;
inline bool OneUserLoginToken::has_user_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void OneUserLoginToken::clear_user_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.user_name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& OneUserLoginToken::user_name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:BSToGS.OneUserLoginToken.user_name)
  return _internal_user_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void OneUserLoginToken::set_user_name(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.user_name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:BSToGS.OneUserLoginToken.user_name)
}
inline std::string* OneUserLoginToken::mutable_user_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_user_name();
  // @@protoc_insertion_point(field_mutable:BSToGS.OneUserLoginToken.user_name)
  return _s;
}
inline const std::string& OneUserLoginToken::_internal_user_name() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.user_name_.Get();
}
inline void OneUserLoginToken::_internal_set_user_name(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.user_name_.Set(value, GetArena());
}
inline std::string* OneUserLoginToken::_internal_mutable_user_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.user_name_.Mutable( GetArena());
}
inline std::string* OneUserLoginToken::release_user_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:BSToGS.OneUserLoginToken.user_name)
  if ((_impl_._has_bits_[0] & 0x00000002u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000002u;
  auto* released = _impl_.user_name_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.user_name_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void OneUserLoginToken::set_allocated_user_name(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.user_name_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.user_name_.IsDefault()) {
          _impl_.user_name_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:BSToGS.OneUserLoginToken.user_name)
}

// optional int32 port = 5;
inline bool OneUserLoginToken::has_port() const {
  bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline void OneUserLoginToken::clear_port() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.port_ = 0;
  _impl_._has_bits_[0] &= ~0x00000010u;
}
inline ::int32_t OneUserLoginToken::port() const {
  // @@protoc_insertion_point(field_get:BSToGS.OneUserLoginToken.port)
  return _internal_port();
}
inline void OneUserLoginToken::set_port(::int32_t value) {
  _internal_set_port(value);
  _impl_._has_bits_[0] |= 0x00000010u;
  // @@protoc_insertion_point(field_set:BSToGS.OneUserLoginToken.port)
}
inline ::int32_t OneUserLoginToken::_internal_port() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.port_;
}
inline void OneUserLoginToken::_internal_set_port(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.port_ = value;
}

// optional string ip = 6;
inline bool OneUserLoginToken::has_ip() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void OneUserLoginToken::clear_ip() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.ip_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline const std::string& OneUserLoginToken::ip() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:BSToGS.OneUserLoginToken.ip)
  return _internal_ip();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void OneUserLoginToken::set_ip(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.ip_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:BSToGS.OneUserLoginToken.ip)
}
inline std::string* OneUserLoginToken::mutable_ip() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_ip();
  // @@protoc_insertion_point(field_mutable:BSToGS.OneUserLoginToken.ip)
  return _s;
}
inline const std::string& OneUserLoginToken::_internal_ip() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.ip_.Get();
}
inline void OneUserLoginToken::_internal_set_ip(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.ip_.Set(value, GetArena());
}
inline std::string* OneUserLoginToken::_internal_mutable_ip() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000004u;
  return _impl_.ip_.Mutable( GetArena());
}
inline std::string* OneUserLoginToken::release_ip() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:BSToGS.OneUserLoginToken.ip)
  if ((_impl_._has_bits_[0] & 0x00000004u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000004u;
  auto* released = _impl_.ip_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.ip_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void OneUserLoginToken::set_allocated_ip(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }
  _impl_.ip_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.ip_.IsDefault()) {
          _impl_.ip_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:BSToGS.OneUserLoginToken.ip)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace BSToGS


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::BSToGS::MsgID> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::BSToGS::MsgID>() {
  return ::BSToGS::MsgID_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_BSToGS_2eproto_2epb_2eh
