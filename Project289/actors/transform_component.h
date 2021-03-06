#pragma once

#include "actor_component.h"

#include "../tools/tinyxml/tinyxml.h"

#include <DirectXMath.h>

class TransformComponent : public ActorComponent {
private:
    DirectX::XMFLOAT4X4 m_transform;

    DirectX::XMFLOAT4 m_forward;
    DirectX::XMFLOAT4 m_up;
    DirectX::XMFLOAT4 m_right;

    DirectX::XMFLOAT4 m_scale;

public:
    static const std::string g_Name;

    TransformComponent();
    TransformComponent(TiXmlElement* pData);

    virtual bool VInit(TiXmlElement* pData) override;
    virtual const std::string& VGetName() const override;
    virtual TiXmlElement* VGenerateXml() override;

    // transform functions
    const DirectX::XMFLOAT4X4& GetTransform4x4f() const;
    DirectX::XMMATRIX GetTransform() const;

    void SetTransform(const DirectX::XMFLOAT4X4& newTransform);
    void SetTransform(const DirectX::FXMMATRIX& newTransform);

    DirectX::XMFLOAT3 GetPosition3f() const;
    DirectX::XMFLOAT4 GetPosition4f() const;
    DirectX::XMVECTOR GetPosition() const;

    DirectX::XMFLOAT3 GetScale3f() const;
    DirectX::XMVECTOR GetScale() const;

    void SetPosition3f(const DirectX::XMFLOAT3& pos);
    void SetPosition4f(const DirectX::XMFLOAT4& pos);
    void SetPosition4x4f(const DirectX::XMFLOAT4X4& pos);
    void SetPosition3(const DirectX::FXMVECTOR& pos);
    void SetPosition4(const DirectX::FXMVECTOR& pos);

    void SetScale3f(const DirectX::XMFLOAT3& sclae);
    void SetScale4f(const DirectX::XMFLOAT4& sclae);
    void SetScale(const DirectX::FXMVECTOR& scale);

    DirectX::XMFLOAT3 GetLookAt3f() const;
    DirectX::XMVECTOR GetLookAt() const;

    DirectX::XMFLOAT3 GetYawPitchRoll3f() const;
    DirectX::XMVECTOR GetYawPitchRoll() const;

    DirectX::XMFLOAT3 GetForward3f() const;
    DirectX::XMFLOAT4 GetForward4f() const;
    DirectX::XMVECTOR GetForward() const;

    DirectX::XMFLOAT3 GetUp3f() const;
    DirectX::XMFLOAT4 GetUp4f() const;
    DirectX::XMVECTOR GetUp() const;

    DirectX::XMFLOAT3 GetRight3f() const;
    DirectX::XMFLOAT4 GetRight4f() const;
    DirectX::XMVECTOR GetRight() const;

private:
    bool Init(TiXmlElement* pData);

    const DirectX::XMFLOAT4 DEFAULT_FORWARD_VECTOR = { 0.0f, 0.0f, 1.0f, 0.0f };
    const DirectX::XMFLOAT4 DEFAULT_UP_VECTOR = { 0.0f, 1.0f, 0.0f, 0.0f };
    const DirectX::XMFLOAT4 DEFAULT_RIGHT_VECTOR = { 1.0f, 0.0f, 0.0f, 0.0f };
    const float EPSILON = 0.001f;
};
