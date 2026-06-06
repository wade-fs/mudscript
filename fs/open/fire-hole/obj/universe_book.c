//渾天水晶
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC + "先天乾坤功\" + YEL + "正卷" + NOR, ({ "universe-book","book" }));
        set_weight(750);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "本");
          set("long","你可以由這本書中所泛出的浩然仙氣感到先天乾坤功\的博大精深。\n");
          set("value", 800);
          set("material", "paper");
          set("no_drop", 1);
          set("no_get", 1);
          set("no_sell", 1);
          set("no_auc", 1);
          set("skill", ([
          "name" : "universe",  // name of the skill
          "exp_required" :  5000000,     // to learn this skill.
          "sen_cost" : 60,              // gin cost every time study this
          "difficulty" : 25,             // modify is gin_cost's (difficulty - int)*5%
          "max_skill":  140
          ]) );
        }
}

int valid_learn(object me)
{
        if(me->query("family/family_name")!="聖火教")
          return -1;
        return 1;
}
