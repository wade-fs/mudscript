//天女散花劍譜()

inherit ITEM;

void create()
{
        set_name("劍譜", ({ "girlsword book","book" }));
        set("title", "天女散花劍法之");
        set_weight(750);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "本");
          set("long","這是一本記載玉女派劍法的劍譜, 裡面錄有玉女派之玄天女散花劍法的劍訣。\n");
          set("value", 800);
          set("material", "paper");
          set("no_drop", 1);
          set("no_get", 1);
          set("no_sell", 1);
          set("no_auc", 1);
          set("no_give", 1);
          set("skill", ([
          "name" : "girlsword",  // name of the skill
          "exp_required" :  300000,     // to learn this skill.
          "sen_cost" : 20,              // gin cost every time study this
          "difficulty" : 25,             // modify is gin_cost's (difficulty - int)*5%
          "max_skill":  30
          ]) );
        }
}

int valid_learn(object me)
{
        if( me->query("family/master_name")!="秦憶詩" && (int)me->query("combat_exp") <= 300000 )
          return -1;
        return 1;
}
