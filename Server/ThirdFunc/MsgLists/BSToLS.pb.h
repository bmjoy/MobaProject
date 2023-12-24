// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BSToLS.proto
// Protobuf C++ Version: 4.26.0-dev

#ifndef GOOGLE_PROTOBUF_INCLUDED_BSToLS_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_BSToLS_2eproto_2epb_2eh

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

#define PROTOBUF_INTERNAL_EXPORT_BSToLS_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_BSToLS_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_BSToLS_2eproto;
namespace BSToLS {
class AskRegister;
struct AskRegisterDefaultTypeInternal;
extern AskRegisterDefaultTypeInternal _AskRegister_default_instance_;
}  // namespace BSToLS
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace BSToLS {
enum MsgID : int {
  eMsgToLSFromBS_Begin = 40960,
  eMsgToLSFromBS_AskRegister = 40961,
  eMsgToLSFromBC_OneClinetLoginCheck = 40962,
  eMsgToLSFromBS_End = 41000,
};

bool MsgID_IsValid(int value);
extern const uint32_t MsgID_internal_data_[];
constexpr MsgID MsgID_MIN = static_cast<MsgID>(40960);
constexpr MsgID MsgID_MAX = static_cast<MsgID>(41000);
constexpr int MsgID_ARRAYSIZE = 41000 + 1;
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

class AskRegister final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:BSToLS.AskRegister) */ {
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
  static ::absl::string_view FullMessageName() { return "BSToLS.AskRegister"; }

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
    kMsgidFieldNumber = 1,
  };
  // optional .BSToLS.MsgID msgid = 1 [default = eMsgToLSFromBS_AskRegister];
  bool has_msgid() const;
  void clear_msgid() ;
  ::BSToLS::MsgID msgid() const;
  void set_msgid(::BSToLS::MsgID value);

  private:
  ::BSToLS::MsgID _internal_msgid() const;
  void _internal_set_msgid(::BSToLS::MsgID value);

  public:
  // @@protoc_insertion_point(class_scope:BSToLS.AskRegister)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 1,
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
    int msgid_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_BSToLS_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// AskRegister

// optional .BSToLS.MsgID msgid = 1 [default = eMsgToLSFromBS_AskRegister];
inline bool AskRegister::has_msgid() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void AskRegister::clear_msgid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.msgid_ = 40961;
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline ::BSToLS::MsgID AskRegister::msgid() const {
  // @@protoc_insertion_point(field_get:BSToLS.AskRegister.msgid)
  return _internal_msgid();
}
inline void AskRegister::set_msgid(::BSToLS::MsgID value) {
  _internal_set_msgid(value);
  _impl_._has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_set:BSToLS.AskRegister.msgid)
}
inline ::BSToLS::MsgID AskRegister::_internal_msgid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return static_cast<::BSToLS::MsgID>(_impl_.msgid_);
}
inline void AskRegister::_internal_set_msgid(::BSToLS::MsgID value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  assert(::BSToLS::MsgID_IsValid(value));
  _impl_.msgid_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace BSToLS


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::BSToLS::MsgID> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::BSToLS::MsgID>() {
  return ::BSToLS::MsgID_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_BSToLS_2eproto_2epb_2eh
