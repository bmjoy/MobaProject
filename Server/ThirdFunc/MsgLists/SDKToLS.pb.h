// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SDKToLS.proto
// Protobuf C++ Version: 4.26.0-dev

#ifndef GOOGLE_PROTOBUF_INCLUDED_SDKToLS_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_SDKToLS_2eproto_2epb_2eh

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

#define PROTOBUF_INTERNAL_EXPORT_SDKToLS_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_SDKToLS_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_SDKToLS_2eproto;
namespace SDKToLS {
class UserLoginRes91;
struct UserLoginRes91DefaultTypeInternal;
extern UserLoginRes91DefaultTypeInternal _UserLoginRes91_default_instance_;
}  // namespace SDKToLS
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace SDKToLS {
enum MsgID : int {
  eMsgToGCFromBS_91UserLoginRes = 1,
};

bool MsgID_IsValid(int value);
extern const uint32_t MsgID_internal_data_[];
constexpr MsgID MsgID_MIN = static_cast<MsgID>(1);
constexpr MsgID MsgID_MAX = static_cast<MsgID>(1);
constexpr int MsgID_ARRAYSIZE = 1 + 1;
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
                                                 1, 1>(
      static_cast<int>(value));
}
inline bool MsgID_Parse(absl::string_view name, MsgID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MsgID>(
      MsgID_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class UserLoginRes91 final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:SDKToLS.UserLoginRes91) */ {
 public:
  inline UserLoginRes91() : UserLoginRes91(nullptr) {}
  ~UserLoginRes91() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR UserLoginRes91(
      ::google::protobuf::internal::ConstantInitialized);

  inline UserLoginRes91(const UserLoginRes91& from) : UserLoginRes91(nullptr, from) {}
  inline UserLoginRes91(UserLoginRes91&& from) noexcept
      : UserLoginRes91(nullptr, std::move(from)) {}
  inline UserLoginRes91& operator=(const UserLoginRes91& from) {
    CopyFrom(from);
    return *this;
  }
  inline UserLoginRes91& operator=(UserLoginRes91&& from) noexcept {
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
  static const UserLoginRes91& default_instance() {
    return *internal_default_instance();
  }
  static inline const UserLoginRes91* internal_default_instance() {
    return reinterpret_cast<const UserLoginRes91*>(
        &_UserLoginRes91_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(UserLoginRes91& a, UserLoginRes91& b) { a.Swap(&b); }
  inline void Swap(UserLoginRes91* other) {
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
  void UnsafeArenaSwap(UserLoginRes91* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  UserLoginRes91* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<UserLoginRes91>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const UserLoginRes91& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const UserLoginRes91& from) { UserLoginRes91::MergeImpl(*this, from); }

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
  void InternalSwap(UserLoginRes91* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "SDKToLS.UserLoginRes91"; }

 protected:
  explicit UserLoginRes91(::google::protobuf::Arena* arena);
  UserLoginRes91(::google::protobuf::Arena* arena, const UserLoginRes91& from);
  UserLoginRes91(::google::protobuf::Arena* arena, UserLoginRes91&& from) noexcept
      : UserLoginRes91(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kGcidFieldNumber = 2,
    kResFieldNumber = 3,
    kMgsidFieldNumber = 1,
  };
  // optional int32 gcid = 2;
  bool has_gcid() const;
  void clear_gcid() ;
  ::int32_t gcid() const;
  void set_gcid(::int32_t value);

  private:
  ::int32_t _internal_gcid() const;
  void _internal_set_gcid(::int32_t value);

  public:
  // optional int32 res = 3;
  bool has_res() const;
  void clear_res() ;
  ::int32_t res() const;
  void set_res(::int32_t value);

  private:
  ::int32_t _internal_res() const;
  void _internal_set_res(::int32_t value);

  public:
  // optional .SDKToLS.MsgID mgsid = 1 [default = eMsgToGCFromBS_91UserLoginRes];
  bool has_mgsid() const;
  void clear_mgsid() ;
  ::SDKToLS::MsgID mgsid() const;
  void set_mgsid(::SDKToLS::MsgID value);

  private:
  ::SDKToLS::MsgID _internal_mgsid() const;
  void _internal_set_mgsid(::SDKToLS::MsgID value);

  public:
  // @@protoc_insertion_point(class_scope:SDKToLS.UserLoginRes91)
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
    ::int32_t gcid_;
    ::int32_t res_;
    int mgsid_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_SDKToLS_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// UserLoginRes91

// optional .SDKToLS.MsgID mgsid = 1 [default = eMsgToGCFromBS_91UserLoginRes];
inline bool UserLoginRes91::has_mgsid() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void UserLoginRes91::clear_mgsid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.mgsid_ = 1;
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline ::SDKToLS::MsgID UserLoginRes91::mgsid() const {
  // @@protoc_insertion_point(field_get:SDKToLS.UserLoginRes91.mgsid)
  return _internal_mgsid();
}
inline void UserLoginRes91::set_mgsid(::SDKToLS::MsgID value) {
  _internal_set_mgsid(value);
  _impl_._has_bits_[0] |= 0x00000004u;
  // @@protoc_insertion_point(field_set:SDKToLS.UserLoginRes91.mgsid)
}
inline ::SDKToLS::MsgID UserLoginRes91::_internal_mgsid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return static_cast<::SDKToLS::MsgID>(_impl_.mgsid_);
}
inline void UserLoginRes91::_internal_set_mgsid(::SDKToLS::MsgID value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  assert(::SDKToLS::MsgID_IsValid(value));
  _impl_.mgsid_ = value;
}

// optional int32 gcid = 2;
inline bool UserLoginRes91::has_gcid() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void UserLoginRes91::clear_gcid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.gcid_ = 0;
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline ::int32_t UserLoginRes91::gcid() const {
  // @@protoc_insertion_point(field_get:SDKToLS.UserLoginRes91.gcid)
  return _internal_gcid();
}
inline void UserLoginRes91::set_gcid(::int32_t value) {
  _internal_set_gcid(value);
  _impl_._has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_set:SDKToLS.UserLoginRes91.gcid)
}
inline ::int32_t UserLoginRes91::_internal_gcid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.gcid_;
}
inline void UserLoginRes91::_internal_set_gcid(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.gcid_ = value;
}

// optional int32 res = 3;
inline bool UserLoginRes91::has_res() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void UserLoginRes91::clear_res() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.res_ = 0;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline ::int32_t UserLoginRes91::res() const {
  // @@protoc_insertion_point(field_get:SDKToLS.UserLoginRes91.res)
  return _internal_res();
}
inline void UserLoginRes91::set_res(::int32_t value) {
  _internal_set_res(value);
  _impl_._has_bits_[0] |= 0x00000002u;
  // @@protoc_insertion_point(field_set:SDKToLS.UserLoginRes91.res)
}
inline ::int32_t UserLoginRes91::_internal_res() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.res_;
}
inline void UserLoginRes91::_internal_set_res(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.res_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace SDKToLS


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::SDKToLS::MsgID> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::SDKToLS::MsgID>() {
  return ::SDKToLS::MsgID_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_SDKToLS_2eproto_2epb_2eh