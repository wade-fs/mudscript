//皇城禁衛軍

#include "/open/capital/capital.h"

inherit NPC;

void create()
{
        set_name("皇宮禁衛軍",({"soldier"}) );
        set("gender","男性");
        set("age",25);
        set("class","soldier");
        set("str",30);
        set("long","皇城禁衛軍是保衛皇宮的先鋒, 均為萬中選一的精英。\n");

        set("combat_exp",3000000);
        set("max_gin",1000);
          set("max_kee",5000);
        set("max_sen",1000);
        set("gin",1000);
         set("kee",5000);
        set("sen",1000);
       set("max_force",4000);
           set("force",4000);
          set("force_factor",10);
         set_skill("blade",100);
         set_skill("parry",100);
         set_skill("dodge",100);
         set_skill("godblade",80);
         set_skill("bss-steps",80);
        map_skill("dodge","bss-steps");
        map_skill("blade","godblade");
         set_skill("bss-parry",80);
             map_skill("parry","bss-parry");
        setup();
        carry_object(CAP_OBJ"Hblade")->wield();
        carry_object(CAP_OBJ"Ns_boots")->wear();
        carry_object(CAP_OBJ"carmor")->wear();
        carry_object(CAP_OBJ"ironshield")->wear();
        carry_object(CAP_OBJ"ironarmband")->wear();

}


void init() {
       object obj;
            add_action("do_kill","kill");
            add_action("do_kill","fight");

        ::init();

            if(interactive(obj=this_player()) && !obj->query_temp("can_in"))
        {
          call_out("kill_ppl",1,obj);
        }
 }
 int kill_ppl(object obj)
 {
            command("say 來人ㄚ,有刺客,快保護皇上!!!");
           kill_ob(obj);
           return 1;
 }
int do_kill()
{
         object me=this_player();
          command("say 來人ㄚ,有刺客,快保護皇上!!!");
         kill_ob(me);
      return 1;
}
