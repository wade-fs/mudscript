//渾天水晶(第八層金晨曦心法)

inherit ITEM;

void create()
{
        set_name("黃水晶", ({ "yellow-crystal","crystal" }));
        set("title", "渾天心法之");
        set_weight(700);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "根");
          set("long","這是一根會發出金光的水晶, 裡面刻有渾天寶鑑第八層金晨曦心法的練功\口訣。\n");
          set("value", 700);
          set("material", "gem");
           set("no_drop", 1);
          set("no_get", 1);
          set("no_sell", 1);
          set("no_auc", 1);
          set("no_give", 1);
          set("skill", ([
          "name" : "superforce",  // name of the skill
          "exp_required" :  1300000,     // to learn this skill.
          "sen_cost" : 40,      // gin cost every time study this
          "difficulty" : 25,             // modify is gin_cost's (difficulty - int)*5%
          "max_skill": 150
          ]) );
        }
}

int valid_learn(object me)
{
        if(me->query("family/family_name")!="聖火教")
          return -1;
        return 1;
}
