//不死印法 by bss
#include <ansi.h>
inherit SKILL;

string *parry_msg =
({

        "\n" + HIY + "$n體內的陰陽二氣快速運轉，正正反反，反反正正，將$N攻擊的內勁化為己用。" + NOR + "\n",

        "\n" + HIR + "面對$N強大的攻勢，$n強運不死印法，將$N那強大的內勁硬是傳到了身後的地上，使地上留下了一個足足有尺餘的腳印。" + NOR + "\n",

        "\n" + MAG + "$n雙手平推而出，陰陽勁氣一吐，再身前形成一道氣牆，將$N猛烈的攻勢抵消掉了。" + NOR + "\n",

});

int valid_enable(string usage) {
int family;
object me=this_player();
if ( me->query("family/family_name") != "東廠")
        return (usage=="parry");
else
 return notify_fail("只有東廠太監才能用不死印法!!\n");

}

string query_parry_msg(string limb){

        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
       if(me->query_skill("taiyiforce",1) < 60)
 {
   write("你的太乙罡氣不夠純熟..無法學習不死印法\n");
   return 0;
 }
        return 1;
}









