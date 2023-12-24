using UnityEngine;
using System.Collections;

namespace BlGame.GameEntity
{
	public enum EntityType{
		Monster = 1,
		Soldier,
		Building,
		Player,
        AltarSoldier,
	}

    public enum ENPCCateChild
    {
        eNPCChild_None = 0,
        eNPCChild_NPC_Per_AtkBuilding,
        eNPCChild_NPC_Per_Bomb,
        eNPCChild_SmallMonster, //СҰ�� 3
        eNPCChild_HugeMonster,  //��Ұ�� 4

        eNPCChild_BUILD_Altar = 10,  //��̳
        eNPCChild_BUILD_Base,        //����
        eNPCChild_BUILD_Shop,        //�̵�
        eNPCChild_BUILD_Tower,       //����

        eNPCChild_BUILD_Summon = 20,

        eNPCCateChild_Ohter,
    };

 
}
