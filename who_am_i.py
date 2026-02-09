#!/usr/bin/env python3
"""
학습자 프로필 관리 유틸리티
이 스크립트는 .studycpp/learner_profile.json 파일의 사용자 정보를 표시하고 수정합니다.
"""

import json
import os
import sys
from datetime import datetime

PROFILE_PATH = ".studycpp/learner_profile.json"

def load_profile():
    """프로필 파일 로드"""
    if not os.path.exists(PROFILE_PATH):
        print(f"오류: 프로필 파일을 찾을 수 없습니다: {PROFILE_PATH}")
        return None
    
    try:
        with open(PROFILE_PATH, 'r', encoding='utf-8') as f:
            return json.load(f)
    except Exception as e:
        print(f"오류: 프로필 파일을 읽을 수 없습니다: {e}")
        return None

def save_profile(profile):
    """프로필 파일 저장"""
    try:
        with open(PROFILE_PATH, 'w', encoding='utf-8') as f:
            json.dump(profile, f, indent=2, ensure_ascii=False)
        return True
    except Exception as e:
        print(f"오류: 프로필 파일을 저장할 수 없습니다: {e}")
        return False

def display_profile(profile):
    """프로필 정보 표시"""
    print("\n" + "="*50)
    print("📚 Modern C++ Study - 학습자 프로필")
    print("="*50)
    print(f"\n사용자 ID: {profile.get('user_id', 'anonymous')}")
    print(f"현재 레벨: {profile.get('level', 0)}")
    
    print("\n=== 주제별 숙련도 ===")
    mastery = profile.get('topic_mastery', {})
    for topic, score in mastery.items():
        bar = "█" * (score // 5) + "░" * (20 - score // 5)
        print(f"{topic:20} [{bar}] {score:3}/100")
    
    print("\n=== 최근 성과 ===")
    recent = profile.get('recent_scores', [])
    if recent:
        for score in recent[-3:]:  # 최근 3개만 표시
            print(f"과제: {score.get('exercise_id', 'N/A')}")
            print(f"  점수: {score.get('rubric', {}).get('total', 0)}/100")
            print(f"  날짜: {score.get('timestamp', 'N/A')}")
    else:
        print("아직 완료한 과제가 없습니다.")
    
    print("\n=== 다음 추천 과제 ===")
    next_rec = profile.get('next_recommendation', {})
    print(f"레벨: {next_rec.get('level', 0)}")
    print(f"집중 주제: {', '.join(next_rec.get('focus_topics', []))}")
    print(f"이유: {next_rec.get('rationale', 'N/A')}")
    
    print("\n=== 학습 연속성 ===")
    streaks = profile.get('streaks', {})
    print(f"✅ 통과: {streaks.get('accepted', 0)}회")
    print(f"🔄 재제출: {streaks.get('resubmit', 0)}회")
    
    print("="*50 + "\n")

def update_user_id(profile):
    """사용자 ID 업데이트"""
    current = profile.get('user_id', 'anonymous')
    print(f"\n현재 사용자 ID: {current}")
    new_id = input("새로운 사용자 ID를 입력하세요 (취소하려면 Enter): ").strip()
    
    if new_id:
        profile['user_id'] = new_id
        if save_profile(profile):
            print(f"✓ 사용자 ID가 '{new_id}'로 업데이트되었습니다!")
            return True
    else:
        print("취소되었습니다.")
    return False

def main():
    """메인 함수"""
    if len(sys.argv) > 1 and sys.argv[1] in ['-h', '--help']:
        print("사용법:")
        print("  python who_am_i.py          # 프로필 표시")
        print("  python who_am_i.py update   # 사용자 ID 업데이트")
        return
    
    profile = load_profile()
    if not profile:
        return
    
    if len(sys.argv) > 1 and sys.argv[1] == 'update':
        update_user_id(profile)
        # 업데이트 후 프로필 다시 표시
        profile = load_profile()
    
    if profile:
        display_profile(profile)

if __name__ == "__main__":
    main()
