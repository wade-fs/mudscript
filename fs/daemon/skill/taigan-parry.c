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
        int level,skill;
        level=me->query("taigan_level",1);
        skill=me->query_skill("taigan-parry",1);
        if(me->query("class")!="taigan"){
                return notify_fail("只有太監能學不死印法");
                return 0;
                }
         if(me->query_skill("taiyiforce",1) < 60)
         {
         write("你的太乙罡\氣不夠純熟..無法學習不死印法\n");
         return 0;
         }
        switch(level){
                case 5:
                        return 1;
                        break;
                case 6:
                        if(skill>80){
                                return notify_fail("你的官品不夠，無法學習更高深的武技。\n");
                                return 0;
                                break;
                                }
                        return 1;
                        break;
                case 7:
                        if(skill>60){
                                return notify_fail("你的官品不夠，無法學習更高深的武技。\n");
                                return 0;
                                break;
                                }
                        return 1;
                        break;
                case 8:
                        if(skill>40){
                                return notify_fail("你的官品不夠，無法學習更高深的武技。\n");
                                return 0;
                                break;
                                }
                        return 1;
                        break;
                case 9:
                        if(skill>20){
                                return notify_fail("你的官品不夠，無法學習更高深的武技。\n");
                                return 0;
                                break;
                                }
                        return 1;
                        break;
                default:
                        write("你不是太監，無法學習此項武技。\n");
                        return 0;
                        break;
  }
}








