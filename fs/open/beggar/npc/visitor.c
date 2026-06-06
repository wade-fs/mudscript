#include <ansi.h>
inherit NPC;

void create()
{
  set_name("登山客",({"visitor"}));
  set("long","一個來此遊玩的客人！\n");
  set("gender","男性");
  set("attitude","friendly");
  set("age",40);
  set("no_kill",1);
  set("inquiry",([
      "打狗棒" : "唔..打狗棒呀，我不曉得耶，但是我最近有撿到一把杖，送給一個小牧童當玩具了。",
      "小牧童" : "他跟他父母回去了呢，好像住在蜀中城裡！",
                ]));
  setup();
}

