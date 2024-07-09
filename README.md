# RunAndJump

## 개요
RunAndJump는 사이드 스크롤 러닝 액션 게임입니다.

일반적인 러닝 액션 게임과는 달리 계속 달리지 않고

뒤돌아 움직일 수 있습니다.

강제스크롤되는 상황에서 함정들을 피해가며 끝에 도달하면 끝나는 게임입니다.

## 링크
- 조작방법
  - [이동](About/README_Move.md)
  - [구르기](About/README_Roll.md)
  - [점프](About/README_Jump.md)
- 게임 내 요소
  - [Trap](About/README_Trap.md)
  - [Moving Platform](About/README_MovingPlatform.md)
  - [Cube](About/README_Cube.md)

## 기술 설명
- 캐릭터에게 제공되는 InputComponent를 통한 조작 구현
- 스테이트 머신, 슬롯, 블렌드 스페이스 등을 이용하여 생동감 있는 캐릭터 구현
- 애님몽타주 제작을 통해 구르기, 공격 이벤트 바인딩 완성
- 뷰타깃 블랜딩을 통한 자연스러운 시점 변화 구현
- 파티클을 이용하여 시각적 완성도 증가
- 위젯을 이용하여 재시작 기능 구현

## 인게임 영상
[![인게임 영상 보러가기](http://img.youtube.com/vi/DKu5fM-nq_4/0.jpg)](https://youtu.be/DKu5fM-nq_4)
