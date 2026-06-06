
// 一陽心法秘笈
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"一陽心法秘笈"NOR, ({"sunforce book","book" }));
        set_weight(100);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "本");
          set("long","這書便是段家歷來武功\精要～一陽心法的秘笈, 然而其中
之絕招『化氣為筆』卻因前代門人保存不善而失傳 。\n");
          set("value",1000);
          set("material", "paper");
          set("skill", ([
          "name" : "sunforce",          // name of the skill
          "exp_required" : 1000,
                                        // to learn this skill.
          "sen_cost" : 25,              // gin cost every time study this
          "difficulty" : 25,
                                        // modify is gin_cost's (difficulty - int)*5%
          "max_skill":  51
          ]) );
        }
}

int valid_learn(object me)
{
        if(me->query("family/family_name")!="段家")
          return -1;
        return 1;
}
