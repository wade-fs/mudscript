//神農氏醫源(shen-nongshi_cure) 作為fun的名稱
/*
魚缸@台北 說 (上午 12:24):
20sec or 看fun 的lv 
魚缸@台北 說 (上午 12:24):
lv 越高越久
魚缸@台北 說 (上午 12:24):
就參考鬥氣？就好了
魚缸@台北 說 (上午 12:24):
or 極火金身
(宅蛙)魔女洋子(建彰：指引未來的自己 只能是現在的自己 說 (上午 12:24):
嗯 極火吧
(宅蛙)魔女洋子(建彰：指引未來的自己 只能是現在的自己 說 (上午 12:25):
效果消失 就是原sk的設定了
(宅蛙)魔女洋子(建彰：指引未來的自己 只能是現在的自己 說 (上午 12:25):
有運 才有減輕busy的效果 
魚缸@台北 說 (上午 12:25):
yes
*/
#include <combat.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
  seteuid(geteuid());
  set_name("神農氏醫譜", ({ "Shen-Nongshi medical book", "book", "medical book", "Shen-Nongshi" }) );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "本");
    set("no_get",1);
    set("no_auc",1);
    set("no_put",1);
    set("no_sell",1);
    set("no_save",1);
    set("no_give",1);
    set("no_drop",1);
//    set("no_sac",1);
//    set("no_steal",1);
  }
  setup();
}

string long()
{
  return @TEXT
    一本看起來很舊且不起眼的書，但是似乎有神力附著在上頭，導致水火不侵。相傳記載
著銀針門起源醫術的有關記載與醫術本源。

TEXT;
}

void init()
{
  object me;
  me = environment();
  if( !this_object()->query("ower") )
  {
    this_object()->set("ower",me->query("id"));
  }

  if(!me) return ;
//  if(!me || !environment(me)) return ;
  me->set_temp("needleup",1); //持有即給予技能使用許可的一般獎勵mark
}

int query_autoload ()
{
  object me;
  me = environment();

  if(me->query("class")=="doctor" || wizardp(me))
  {
    return 1;
  }
  return 0;
}
