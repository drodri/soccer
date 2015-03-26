// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: game_status.proto

#ifndef PROTOBUF_game_5fstatus_2eproto__INCLUDED
#define PROTOBUF_game_5fstatus_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace soccer {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_game_5fstatus_2eproto();
void protobuf_AssignDesc_game_5fstatus_2eproto();
void protobuf_ShutdownFile_game_5fstatus_2eproto();

class Player;
class Ball;
class GameStatus;

// ===================================================================

class Player : public ::google::protobuf::Message {
 public:
  Player();
  virtual ~Player();

  Player(const Player& from);

  inline Player& operator=(const Player& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Player& default_instance();

  void Swap(Player* other);

  // implements Message ----------------------------------------------

  inline Player* New() const { return New(NULL); }

  Player* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Player& from);
  void MergeFrom(const Player& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Player* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::int32 id() const;
  inline void set_id(::google::protobuf::int32 value);

  // required float x = 2;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 2;
  inline float x() const;
  inline void set_x(float value);

  // required float y = 3;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 3;
  inline float y() const;
  inline void set_y(float value);

  // @@protoc_insertion_point(class_scope:soccer.Player)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();

  // helper for ByteSize()
  int RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 id_;
  float x_;
  float y_;
  friend void  protobuf_AddDesc_game_5fstatus_2eproto();
  friend void protobuf_AssignDesc_game_5fstatus_2eproto();
  friend void protobuf_ShutdownFile_game_5fstatus_2eproto();

  void InitAsDefaultInstance();
  static Player* default_instance_;
};
// -------------------------------------------------------------------

class Ball : public ::google::protobuf::Message {
 public:
  Ball();
  virtual ~Ball();

  Ball(const Ball& from);

  inline Ball& operator=(const Ball& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Ball& default_instance();

  void Swap(Ball* other);

  // implements Message ----------------------------------------------

  inline Ball* New() const { return New(NULL); }

  Ball* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Ball& from);
  void MergeFrom(const Ball& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Ball* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required float x = 1;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 1;
  inline float x() const;
  inline void set_x(float value);

  // required float y = 2;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 2;
  inline float y() const;
  inline void set_y(float value);

  // @@protoc_insertion_point(class_scope:soccer.Ball)
 private:
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();

  // helper for ByteSize()
  int RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  float x_;
  float y_;
  friend void  protobuf_AddDesc_game_5fstatus_2eproto();
  friend void protobuf_AssignDesc_game_5fstatus_2eproto();
  friend void protobuf_ShutdownFile_game_5fstatus_2eproto();

  void InitAsDefaultInstance();
  static Ball* default_instance_;
};
// -------------------------------------------------------------------

class GameStatus : public ::google::protobuf::Message {
 public:
  GameStatus();
  virtual ~GameStatus();

  GameStatus(const GameStatus& from);

  inline GameStatus& operator=(const GameStatus& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GameStatus& default_instance();

  void Swap(GameStatus* other);

  // implements Message ----------------------------------------------

  inline GameStatus* New() const { return New(NULL); }

  GameStatus* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GameStatus& from);
  void MergeFrom(const GameStatus& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GameStatus* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .soccer.Ball ball = 1;
  inline bool has_ball() const;
  inline void clear_ball();
  static const int kBallFieldNumber = 1;
  inline const ::soccer::Ball& ball() const;
  inline ::soccer::Ball* mutable_ball();
  inline ::soccer::Ball* release_ball();
  inline void set_allocated_ball(::soccer::Ball* ball);

  // repeated .soccer.Player players = 2;
  inline int players_size() const;
  inline void clear_players();
  static const int kPlayersFieldNumber = 2;
  inline const ::soccer::Player& players(int index) const;
  inline ::soccer::Player* mutable_players(int index);
  inline ::soccer::Player* add_players();
  inline const ::google::protobuf::RepeatedPtrField< ::soccer::Player >&
      players() const;
  inline ::google::protobuf::RepeatedPtrField< ::soccer::Player >*
      mutable_players();

  // @@protoc_insertion_point(class_scope:soccer.GameStatus)
 private:
  inline void set_has_ball();
  inline void clear_has_ball();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::soccer::Ball* ball_;
  ::google::protobuf::RepeatedPtrField< ::soccer::Player > players_;
  friend void  protobuf_AddDesc_game_5fstatus_2eproto();
  friend void protobuf_AssignDesc_game_5fstatus_2eproto();
  friend void protobuf_ShutdownFile_game_5fstatus_2eproto();

  void InitAsDefaultInstance();
  static GameStatus* default_instance_;
};
// ===================================================================


// ===================================================================

// Player

// required int32 id = 1;
inline bool Player::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Player::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Player::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Player::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 Player::id() const {
  // @@protoc_insertion_point(field_get:soccer.Player.id)
  return id_;
}
inline void Player::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:soccer.Player.id)
}

// required float x = 2;
inline bool Player::has_x() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Player::set_has_x() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Player::clear_has_x() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Player::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline float Player::x() const {
  // @@protoc_insertion_point(field_get:soccer.Player.x)
  return x_;
}
inline void Player::set_x(float value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:soccer.Player.x)
}

// required float y = 3;
inline bool Player::has_y() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Player::set_has_y() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Player::clear_has_y() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Player::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline float Player::y() const {
  // @@protoc_insertion_point(field_get:soccer.Player.y)
  return y_;
}
inline void Player::set_y(float value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:soccer.Player.y)
}

// -------------------------------------------------------------------

// Ball

// required float x = 1;
inline bool Ball::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Ball::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Ball::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Ball::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline float Ball::x() const {
  // @@protoc_insertion_point(field_get:soccer.Ball.x)
  return x_;
}
inline void Ball::set_x(float value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:soccer.Ball.x)
}

// required float y = 2;
inline bool Ball::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Ball::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Ball::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Ball::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline float Ball::y() const {
  // @@protoc_insertion_point(field_get:soccer.Ball.y)
  return y_;
}
inline void Ball::set_y(float value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:soccer.Ball.y)
}

// -------------------------------------------------------------------

// GameStatus

// required .soccer.Ball ball = 1;
inline bool GameStatus::has_ball() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GameStatus::set_has_ball() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GameStatus::clear_has_ball() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GameStatus::clear_ball() {
  if (ball_ != NULL) ball_->::soccer::Ball::Clear();
  clear_has_ball();
}
inline const ::soccer::Ball& GameStatus::ball() const {
  // @@protoc_insertion_point(field_get:soccer.GameStatus.ball)
  return ball_ != NULL ? *ball_ : *default_instance_->ball_;
}
inline ::soccer::Ball* GameStatus::mutable_ball() {
  set_has_ball();
  if (ball_ == NULL) {
    ball_ = new ::soccer::Ball;
  }
  // @@protoc_insertion_point(field_mutable:soccer.GameStatus.ball)
  return ball_;
}
inline ::soccer::Ball* GameStatus::release_ball() {
  clear_has_ball();
  ::soccer::Ball* temp = ball_;
  ball_ = NULL;
  return temp;
}
inline void GameStatus::set_allocated_ball(::soccer::Ball* ball) {
  delete ball_;
  ball_ = ball;
  if (ball) {
    set_has_ball();
  } else {
    clear_has_ball();
  }
  // @@protoc_insertion_point(field_set_allocated:soccer.GameStatus.ball)
}

// repeated .soccer.Player players = 2;
inline int GameStatus::players_size() const {
  return players_.size();
}
inline void GameStatus::clear_players() {
  players_.Clear();
}
inline const ::soccer::Player& GameStatus::players(int index) const {
  // @@protoc_insertion_point(field_get:soccer.GameStatus.players)
  return players_.Get(index);
}
inline ::soccer::Player* GameStatus::mutable_players(int index) {
  // @@protoc_insertion_point(field_mutable:soccer.GameStatus.players)
  return players_.Mutable(index);
}
inline ::soccer::Player* GameStatus::add_players() {
  // @@protoc_insertion_point(field_add:soccer.GameStatus.players)
  return players_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::soccer::Player >&
GameStatus::players() const {
  // @@protoc_insertion_point(field_list:soccer.GameStatus.players)
  return players_;
}
inline ::google::protobuf::RepeatedPtrField< ::soccer::Player >*
GameStatus::mutable_players() {
  // @@protoc_insertion_point(field_mutable_list:soccer.GameStatus.players)
  return &players_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace soccer

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_game_5fstatus_2eproto__INCLUDED
