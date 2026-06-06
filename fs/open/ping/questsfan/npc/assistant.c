inherit NPC;  //副鏢頭 by dhk 2000.4.22
#include <ansi.h>
#include "/open/open.h"

void create()
{
    set_name("副鏢頭",({"mercenary assistant","assistant","mercenary"}) );
    set("title","" + HIY + "威武" + NOR + "鏢局");
    set("gender", "男性");
    set("age",90);
    set("attitude", "peaceful");
    set("long", "他是威武鏢局副鏢頭，現在正代理外出不在的總鏢頭，有什\n"
               +"麼找他準沒錯。\n");
    set("kee",2000);
    set("max_kee",2000);
    set("combat_exp",70000);
    set("max_force",2000);
    set("class","blademan");
    set_skill("move",40);
    set_skill("force",80);
    set_skill("dodge",60);
    set_skill("parry",70);
    set_skill("blade",80);
    set_skill("gold-blade",80);
    set_skill("fly-steps",80);
    set_skill("sixforce",80);
    map_skill("blade","gold-blade");
    map_skill("parry","gold-blade");
    map_skill("dodge","fly-steps");
    map_skill("move","fly-steps");
    map_skill("force","sixforce");
    set_temp("apply/armor",100);
    set("force_factor",9);

    setup();
}
int accept_kill(object who)
{
  return 1;
}
int accept_fight(object who)
{
  return 1;
}
int accept_object(object me, object obj)
{
    object bluetooth=new("/open/ping/questsfan/obj/kingblade.c");
    if( obj->query("id") == "leader_letter" )
      {
        command("bow "+getuid(me));
        command("say 閣下救了我們總鏢頭，真是太感謝了。");
        if( me->query("family/family_name") == "段家" && me->query_temp("helpman") == 2 )
          {
            command("say 這是總鏢頭在信中交代要我交於你的東西，請收下。\n");
            me->set("helpman",3);
            bluetooth->move(me);
          }
        destruct(obj);
      }
    else
      command("? "+getuid(me));
    return 1;
}
