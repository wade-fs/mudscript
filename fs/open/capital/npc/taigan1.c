//增加撿拾道具的功能 為了稍微減輕系統負擔 by blazakira 2010/10/20

#include <ansi.h>
inherit NPC;
void create()
{
          set_name("守衛太監",({"soldier"}));
        set("gender","男性");
        set("age",30);
        set("attitude", "heroism");
        set("str",45);
        set("cor",45);
        set("cps",45);
        set("con",45);
        set("family/family_name","東廠");
        set("title","大內高手");

        set("long","保護皇城安全的太監，盡忠職守，不茍言笑。\n");
        set("combat_exp",3000000);
          set("force",5000);
          set("max_force",5000);
        set("max_kee",5000);
        set("kee",5000);
       set("force_factor",10);

          set_skill("unarmed",100);
          set_skill("parry",100);
          set_skill("force",100);
          set_skill("dodge",100);
          set_skill("taiganfist",100);
          set_skill("taigan-steps",90);
          set_skill("taiyiforce",100);
          set_skill("taigan-parry",90);
        map_skill("unarmed","taiganfist");
        map_skill("parry","taigan-parry");
        map_skill("dodge","taigan-steps");
        map_skill("force","taiyiforce");

        setup();

        add_money("gold",5);
}

void init() 
{
  object obj;
  ::init();

  call_out("greeting", 1, this_player());

  if(interactive(obj=this_player()) && !obj->query_temp("can_in"))
  {
    call_out("kill_ppl",1,obj);
  }
}

void greeting()
{
//基本上是針對純喫茶 小拉大龍棕 喚雲扇等 生活物資
  object *inv,ob;
  int i;
  ob=this_object();
  inv=all_inventory(environment(ob));
  for(i=0;i<sizeof(inv);i++){
    if(!inv[i]) continue;
    if(!inv[i]->query("食物") && !inv[i]->query("液體") && inv[i]->query("id") != "cloud fan") continue; //需注意該房間是否固定場景的物件
    message_vision(HIC + "$N以很遺憾的心情將"+inv[i]->query("name")+HIC + "("+inv[i]->query("id")+HIC + ")歸入塵土風逝。\n" + NOR,ob);
    destruct(inv[i]);
  }
}

int kill_ppl(object obj)
{
              command("say 來人ㄚ,有刺客,快保護皇上!!!");
              kill_ob(obj);
             return 1;
}
