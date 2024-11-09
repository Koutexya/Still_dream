#pragma once
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include<DxLib.h>
#include<string>

#include"../../JsonMaster/JsonManager/JsonManager.h"

namespace dream
{
    /// @brief  �Q�[���I�u�W�F�N�g�̊��N���X
    class GameObject
    {
    public:
        /// @brief  �R���X�g���N�^
        /// @param  tagName=�I�u�W�F�N�g��
        GameObject(std::string tagName);

        /// @brief  �f�X�g���N�^
        virtual ~GameObject();

        /// @brief  �X�V
        /// @param  deltaTime=�f���^�^�C��
        virtual void Update(float deltaTime) = 0;

        /// @brief  �`��
        virtual void Draw() = 0;

        /// @brief  ���쏈��
        virtual void Input() {};

        /// @brief  ��������
        /// @param  KeyType=���͂��ꂽ�L�[
        virtual void Move(int KeyType) {};

        /// @brief  �^�O���擾
        /// @return �^�O��
        std::string GetTagName()const { return mTag; }

        /// @brief  ���W�擾
        /// @return �I�u�W�F�N�g�̈ʒu
        const VECTOR& GetObjPos()const { return mPos; }



    private:
        VECTOR mPos;    //�I�u�W�F�N�g�ʒu
        std::string mTag;   //�I�u�W�F�N�g���
    };
}



#endif _GAMEOBJECT_H_
