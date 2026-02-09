#!/bin/bash
# n8n Docker 이미지를 사내 레지스트리로 업로드하는 스크립트

REGISTRY="abis.ahnlab.com/eps-docker-release-local"

echo "=== 1. x86_64(amd64)용 이미지 다운로드 ==="
docker pull --platform linux/amd64 postgres:16
docker pull --platform linux/amd64 docker.n8n.io/n8nio/n8n

echo "=== 2. 사내 레지스트리용 태그 지정 ==="
docker tag postgres:16 ${REGISTRY}/postgres:16
docker tag docker.n8n.io/n8nio/n8n ${REGISTRY}/n8nio/n8n:latest

echo "=== 3. 사내 레지스트리에 푸시 ==="
docker push ${REGISTRY}/postgres:16
docker push ${REGISTRY}/n8nio/n8n:latest

echo "=== 완료! ==="
echo "업로드된 이미지:"
echo "  - ${REGISTRY}/postgres:16"
echo "  - ${REGISTRY}/n8nio/n8n:latest"
