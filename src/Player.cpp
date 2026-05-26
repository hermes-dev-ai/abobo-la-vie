#include "Player.hpp"

void Player::Init(Vector3 pos) {
  position = pos;
  velocity = {0};
  angle = 0;
  pitch = 0;
  speed = 8.0f;
  model = LoadModelFromMesh(GenMeshCylinder(0.4f, 1.8f, 8));
}

void Player::Update(float dt) {
  HandleInput(dt);
  position = Vector3Add(position, Vector3Scale(velocity, dt));
  velocity = Vector3Scale(velocity, 0.85f);
  // Ground clamp
  if (position.y < 0) { position.y = 0; velocity.y = 0; }
}

void Player::HandleInput(float dt) {
  Vector3 move = {0};
  if (IsKeyDown(KEY_W)) move.z -= 1;
  if (IsKeyDown(KEY_S)) move.z += 1;
  if (IsKeyDown(KEY_A)) move.x -= 1;
  if (IsKeyDown(KEY_D)) move.x += 1;

  if (IsKeyDown(KEY_LEFT)) angle -= 2.5f * dt;
  if (IsKeyDown(KEY_RIGHT)) angle += 2.5f * dt;

  if (Vector3Length(move) > 0) move = Vector3Normalize(move);

  Matrix rot = MatrixRotateY(angle);
  Vector3 forward = { rot.m8, 0, rot.m10 };
  Vector3 right = { rot.m0, 0, rot.m2 };

  velocity = Vector3Add(velocity, Vector3Scale(forward, -move.z * speed * dt));
  velocity = Vector3Add(velocity, Vector3Scale(right, move.x * speed * dt));

  // Sprint
  if (IsKeyDown(KEY_LEFT_SHIFT)) velocity = Vector3Scale(velocity, 1.5f);
}

Vector3 Player::GetForward() const {
  Matrix rot = MatrixRotateY(angle);
  return {-rot.m8, 0, -rot.m10};
}

BoundingBox Player::GetBBox() const {
  return {{position.x-0.4f,position.y,position.z-0.4f},{position.x+0.4f,position.y+1.8f,position.z+0.4f}};
}

void Player::Render() {
  DrawModel(model, position, 1, BLUE);
  // Head
  DrawSphere({position.x, position.y+1.8f, position.z}, 0.25f, ColorBrightness(BLUE, 0.2f));
}

void Player::Unload() {
  UnloadModel(model);
}