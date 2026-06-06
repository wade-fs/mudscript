//增加解謎的線索，因為後面很容易死替身(or 真身)所以這線索明朗化一點 by blazakira 2011/6/14

inherit NPC;
#include "/open/open.h"
#include <ansi.h>
string do_key();
void create()
{
    set_name("強壯的樵夫",({"wooder"}) );
    set("gender", "男性");
    set("age",45);
    set("attitude", "peaceful");
    set("long","段家嫡族負責看哨的樵夫，似乎持有木柵的鑰匙。\n");
    set("kee",20000);
    set("max_kee",20000);
    set("combat_exp",3200000);
    set("inquiry", ([
      "木柵鑰匙" : (: do_key :),
    ]));
    setup();
    carry_object("/open/center/obj/torch");
    add_money("silver",20);
}

string do_key()
{
  object me=this_player();
  object key=new("/open/ping/questsfan/obj/key");
  if(me->query_temp("key_ok")!=1)
  {
    if( me->query("family/family_name")=="段家" && me->query("now_start")==1)
    {
      command("say 守關四天王各有所好，你要隨機應變！");
      message_vision("$N交給$n一只大木柵柵門鑰匙。\n",this_object(),me);
      key->move(me);
      me->set_temp("key_ok",1);
      return("祝你好運!");
    }
    else
    {
      return("你說啥, 跟我有關係嗎？\n");
    }
  }
  else
    return("我不是給你了嗎??\n");
}
