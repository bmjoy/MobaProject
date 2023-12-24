// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BSToGC.proto
// Protobuf C++ Version: 4.26.0-dev

#ifndef GOOGLE_PROTOBUF_INCLUDED_BSToGC_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_BSToGC_2eproto_2epb_2eh

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

#define PROTOBUF_INTERNAL_EXPORT_BSToGC_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_BSToGC_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_BSToGC_2eproto;
namespace BSToGC {
class AskGateAddressRet;
struct AskGateAddressRetDefaultTypeInternal;
extern AskGateAddressRetDefaultTypeInternal _AskGateAddressRet_default_instance_;
class ClinetLoginCheckRet;
struct ClinetLoginCheckRetDefaultTypeInternal;
extern ClinetLoginCheckRetDefaultTypeInternal _ClinetLoginCheckRet_default_instance_;
}  // namespace BSToGC
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace BSToGC {
enum MsgID : int {
  eMsgToGCFromBS_AskGateAddressRet = 203,
  eMsgToGCFromBS_OneClinetLoginCheckRet = 204,
};

bool MsgID_IsValid(int value);
extern const uint32_t MsgID_internal_data_[];
constexpr MsgID MsgID_MIN = static_cast<MsgID>(203);
constexpr MsgID MsgID_MAX = static_cast<MsgID>(204);
constexpr int MsgID_ARRAYSIZE = 204 + 1;
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
                                                 203, 204>(
      static_cast<int>(value));
}
inline bool MsgID_Parse(absl::string_view name, MsgID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MsgID>(
      MsgID_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class ClinetLoginCheckRet final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:BSToGC.ClinetLoginCheckRet) */ {
 public:
  inline ClinetLoginCheckRet() : ClinetLoginCheckRet(nullptr) {}
  ~ClinetLoginCheckRet() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR ClinetLoginCheckRet(
      ::google::protobuf::internal::ConstantInitialized);

  inline ClinetLoginCheckRet(const ClinetLoginCheckRet& from) : ClinetLoginCheckRet(nullptr, from) {}
  inline ClinetLoginCheckRet(ClinetLoginCheckRet&& from) noexcept
      : ClinetLoginCheckRet(nullptr, std::move(from)) {}
  inline ClinetLoginCheckRet& operator=(const ClinetLoginCheckRet& from) {
    CopyFrom(from);
    return *this;
  }
  inline ClinetLoginCheckRet& operator=(ClinetLoginCheckRet&& from) noexcept {
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
  static const ClinetLoginCheckRet& default_instance() {
    return *internal_default_instance();
  }
  static inline const ClinetLoginCheckRet* internal_default_instance() {
    return reinterpret_cast<const ClinetLoginCheckRet*>(
        &_ClinetLoginCheckRet_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(ClinetLoginCheckRet& a, ClinetLoginCheckRet& b) { a.Swap(&b); }
  inline void Swap(ClinetLoginCheckRet* other) {
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
  void UnsafeArenaSwap(ClinetLoginCheckRet* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ClinetLoginCheckRet* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<ClinetLoginCheckRet>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const ClinetLoginCheckRet& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const ClinetLoginCheckRet& from) { ClinetLoginCheckRet::MergeImpl(*this, from); }

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
  void InternalSwap(ClinetLoginCheckRet* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "BSToGC.ClinetLoginCheckRet"; }

 protected:
  explicit ClinetLoginCheckRet(::google::protobuf::Arena* arena);
  ClinetLoginCheckRet(::google::protobuf::Arena* arena, const ClinetLoginCheckRet& from);
  ClinetLoginCheckRet(::google::protobuf::Arena* arena, ClinetLoginCheckRet&& from) noexcept
      : ClinetLoginCheckRet(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kLoginSuccessFieldNumber = 2,
    kMgsidFieldNumber = 1,
  };
  // optional uint32 login_success = 2;
  bool has_login_success() const;
  void clear_login_success() ;
  ::uint32_t login_success() const;
  void set_login_success(::uint32_t value);

  private:
  ::uint32_t _internal_login_success() const;
  void _internal_set_login_success(::uint32_t value);

  public:
  // optional .BSToGC.MsgID mgsid = 1 [default = eMsgToGCFromBS_OneClinetLoginCheckRet];
  bool has_mgsid() const;
  void clear_mgsid() ;
  ::BSToGC::MsgID mgsid() const;
  void set_mgsid(::BSToGC::MsgID value);

  private:
  ::BSToGC::MsgID _internal_mgsid() const;
  void _internal_set_mgsid(::BSToGC::MsgID value);

  public:
  // @@protoc_insertion_point(class_scope:BSToGC.ClinetLoginCheckRet)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 1,
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
    ::uint32_t login_success_;
    int mgsid_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_BSToGC_2eproto;
};
// -------------------------------------------------------------------

class AskGateAddressRet final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:BSToGC.AskGateAddressRet) */ {
 public:
  inline AskGateAddressRet() : AskGateAddressRet(nullptr) {}
  ~AskGateAddressRet() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR AskGateAddressRet(
      ::google::protobuf::internal::ConstantInitialized);

  inline AskGateAddressRet(const AskGateAddressRet& from) : AskGateAddressRet(nullptr, from) {}
  inline AskGateAddressRet(AskGateAddressRet&& from) noexcept
      : AskGateAddressRet(nullptr, std::move(from)) {}
  inline AskGateAddressRet& operator=(const AskGateAddressRet& from) {
    CopyFrom(from);
    return *this;
  }
  inline AskGateAddressRet& operator=(AskGateAddressRet&& from) noexcept {
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
  static const AskGateAddressRet& default_instance() {
    return *internal_default_instance();
  }
  static inline const AskGateAddressRet* internal_default_instance() {
    return reinterpret_cast<const AskGateAddressRet*>(
        &_AskGateAddressRet_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(AskGateAddressRet& a, AskGateAddressRet& b) { a.Swap(&b); }
  inline void Swap(AskGateAddressRet* other) {
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
  void UnsafeArenaSwap(AskGateAddressRet* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  AskGateAddressRet* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<AskGateAddressRet>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const AskGateAddressRet& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const AskGateAddressRet& from) { AskGateAddressRet::MergeImpl(*this, from); }

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
  void InternalSwap(AskGateAddressRet* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "BSToGC.AskGateAddressRet"; }

 protected:
  explicit AskGateAddressRet(::google::protobuf::Arena* arena);
  AskGateAddressRet(::google::protobuf::Arena* arena, const AskGateAddressRet& from);
  AskGateAddressRet(::google::protobuf::Arena* arena, AskGateAddressRet&& from) noexcept
      : AskGateAddressRet(arena) {
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
    kMgsidFieldNumber = 1,
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
  // optional .BSToGC.MsgID mgsid = 1 [default = eMsgToGCFromBS_AskGateAddressRet];
  bool has_mgsid() const;
  void clear_mgsid() ;
  ::BSToGC::MsgID mgsid() const;
  void set_mgsid(::BSToGC::MsgID value);

  private:
  ::BSToGC::MsgID _internal_mgsid() const;
  void _internal_set_mgsid(::BSToGC::MsgID value);

  public:
  // @@protoc_insertion_point(class_scope:BSToGC.AskGateAddressRet)
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
    int mgsid_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_BSToGC_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// AskGateAddressRet

// optional .BSToGC.MsgID mgsid = 1 [default = eMsgToGCFromBS_AskGateAddressRet];
inline bool AskGateAddressRet::has_mgsid() const {
  bool value = (_impl_._has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline void AskGateAddressRet::clear_mgsid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.mgsid_ = 203;
  _impl_._has_bits_[0] &= ~0x00000020u;
}
inline ::BSToGC::MsgID AskGateAddressRet::mgsid() const {
  // @@protoc_insertion_point(field_get:BSToGC.AskGateAddressRet.mgsid)
  return _internal_mgsid();
}
inline void AskGateAddressRet::set_mgsid(::BSToGC::MsgID value) {
  _internal_set_mgsid(value);
  _impl_._has_bits_[0] |= 0x00000020u;
  // @@protoc_insertion_point(field_set:BSToGC.AskGateAddressRet.mgsid)
}
inline ::BSToGC::MsgID AskGateAddressRet::_internal_mgsid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return static_cast<::BSToGC::MsgID>(_impl_.mgsid_);
}
inline void AskGateAddressRet::_internal_set_mgsid(::BSToGC::MsgID value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  assert(::BSToGC::MsgID_IsValid(value));
  _impl_.mgsid_ = value;
}

// optional int32 gateclient = 2;
inline bool AskGateAddressRet::has_gateclient() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline void AskGateAddressRet::clear_gateclient() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.gateclient_ = 0;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline ::int32_t AskGateAddressRet::gateclient() const {
  // @@protoc_insertion_point(field_get:BSToGC.AskGateAddressRet.gateclient)
  return _internal_gateclient();
}
inline void AskGateAddressRet::set_gateclient(::int32_t value) {
  _internal_set_gateclient(value);
  _impl_._has_bits_[0] |= 0x00000008u;
  // @@protoc_insertion_point(field_set:BSToGC.AskGateAddressRet.gateclient)
}
inline ::int32_t AskGateAddressRet::_internal_gateclient() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.gateclient_;
}
inline void AskGateAddressRet::_internal_set_gateclient(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.gateclient_ = value;
}

// optional string token = 3;
inline bool AskGateAddressRet::has_token() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void AskGateAddressRet::clear_token() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.token_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& AskGateAddressRet::token() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:BSToGC.AskGateAddressRet.token)
  return _internal_token();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void AskGateAddressRet::set_token(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.token_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:BSToGC.AskGateAddressRet.token)
}
inline std::string* AskGateAddressRet::mutable_token() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_token();
  // @@protoc_insertion_point(field_mutable:BSToGC.AskGateAddressRet.token)
  return _s;
}
inline const std::string& AskGateAddressRet::_internal_token() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.token_.Get();
}
inline void AskGateAddressRet::_internal_set_token(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.token_.Set(value, GetArena());
}
inline std::string* AskGateAddressRet::_internal_mutable_token() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.token_.Mutable( GetArena());
}
inline std::string* AskGateAddressRet::release_token() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:BSToGC.AskGateAddressRet.token)
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
inline void AskGateAddressRet::set_allocated_token(std::string* value) {
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
  // @@protoc_insertion_point(field_set_allocated:BSToGC.AskGateAddressRet.token)
}

// optional string user_name = 4;
inline bool AskGateAddressRet::has_user_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void AskGateAddressRet::clear_user_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.user_name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& AskGateAddressRet::user_name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:BSToGC.AskGateAddressRet.user_name)
  return _internal_user_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void AskGateAddressRet::set_user_name(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.user_name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:BSToGC.AskGateAddressRet.user_name)
}
inline std::string* AskGateAddressRet::mutable_user_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_user_name();
  // @@protoc_insertion_point(field_mutable:BSToGC.AskGateAddressRet.user_name)
  return _s;
}
inline const std::string& AskGateAddressRet::_internal_user_name() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.user_name_.Get();
}
inline void AskGateAddressRet::_internal_set_user_name(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.user_name_.Set(value, GetArena());
}
inline std::string* AskGateAddressRet::_internal_mutable_user_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.user_name_.Mutable( GetArena());
}
inline std::string* AskGateAddressRet::release_user_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:BSToGC.AskGateAddressRet.user_name)
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
inline void AskGateAddressRet::set_allocated_user_name(std::string* value) {
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
  // @@protoc_insertion_point(field_set_allocated:BSToGC.AskGateAddressRet.user_name)
}

// optional int32 port = 5;
inline bool AskGateAddressRet::has_port() const {
  bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline void AskGateAddressRet::clear_port() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.port_ = 0;
  _impl_._has_bits_[0] &= ~0x00000010u;
}
inline ::int32_t AskGateAddressRet::port() const {
  // @@protoc_insertion_point(field_get:BSToGC.AskGateAddressRet.port)
  return _internal_port();
}
inline void AskGateAddressRet::set_port(::int32_t value) {
  _internal_set_port(value);
  _impl_._has_bits_[0] |= 0x00000010u;
  // @@protoc_insertion_point(field_set:BSToGC.AskGateAddressRet.port)
}
inline ::int32_t AskGateAddressRet::_internal_port() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.port_;
}
inline void AskGateAddressRet::_internal_set_port(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.port_ = value;
}

// optional string ip = 6;
inline bool AskGateAddressRet::has_ip() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void AskGateAddressRet::clear_ip() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.ip_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline const std::string& AskGateAddressRet::ip() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:BSToGC.AskGateAddressRet.ip)
  return _internal_ip();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void AskGateAddressRet::set_ip(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.ip_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:BSToGC.AskGateAddressRet.ip)
}
inline std::string* AskGateAddressRet::mutable_ip() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_ip();
  // @@protoc_insertion_point(field_mutable:BSToGC.AskGateAddressRet.ip)
  return _s;
}
inline const std::string& AskGateAddressRet::_internal_ip() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.ip_.Get();
}
inline void AskGateAddressRet::_internal_set_ip(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.ip_.Set(value, GetArena());
}
inline std::string* AskGateAddressRet::_internal_mutable_ip() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000004u;
  return _impl_.ip_.Mutable( GetArena());
}
inline std::string* AskGateAddressRet::release_ip() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:BSToGC.AskGateAddressRet.ip)
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
inline void AskGateAddressRet::set_allocated_ip(std::string* value) {
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
  // @@protoc_insertion_point(field_set_allocated:BSToGC.AskGateAddressRet.ip)
}

// -------------------------------------------------------------------

// ClinetLoginCheckRet

// optional .BSToGC.MsgID mgsid = 1 [default = eMsgToGCFromBS_OneClinetLoginCheckRet];
inline bool ClinetLoginCheckRet::has_mgsid() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void ClinetLoginCheckRet::clear_mgsid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.mgsid_ = 204;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline ::BSToGC::MsgID ClinetLoginCheckRet::mgsid() const {
  // @@protoc_insertion_point(field_get:BSToGC.ClinetLoginCheckRet.mgsid)
  return _internal_mgsid();
}
inline void ClinetLoginCheckRet::set_mgsid(::BSToGC::MsgID value) {
  _internal_set_mgsid(value);
  _impl_._has_bits_[0] |= 0x00000002u;
  // @@protoc_insertion_point(field_set:BSToGC.ClinetLoginCheckRet.mgsid)
}
inline ::BSToGC::MsgID ClinetLoginCheckRet::_internal_mgsid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return static_cast<::BSToGC::MsgID>(_impl_.mgsid_);
}
inline void ClinetLoginCheckRet::_internal_set_mgsid(::BSToGC::MsgID value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  assert(::BSToGC::MsgID_IsValid(value));
  _impl_.mgsid_ = value;
}

// optional uint32 login_success = 2;
inline bool ClinetLoginCheckRet::has_login_success() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void ClinetLoginCheckRet::clear_login_success() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.login_success_ = 0u;
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline ::uint32_t ClinetLoginCheckRet::login_success() const {
  // @@protoc_insertion_point(field_get:BSToGC.ClinetLoginCheckRet.login_success)
  return _internal_login_success();
}
inline void ClinetLoginCheckRet::set_login_success(::uint32_t value) {
  _internal_set_login_success(value);
  _impl_._has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_set:BSToGC.ClinetLoginCheckRet.login_success)
}
inline ::uint32_t ClinetLoginCheckRet::_internal_login_success() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.login_success_;
}
inline void ClinetLoginCheckRet::_internal_set_login_success(::uint32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.login_success_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace BSToGC


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::BSToGC::MsgID> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::BSToGC::MsgID>() {
  return ::BSToGC::MsgID_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_BSToGC_2eproto_2epb_2eh