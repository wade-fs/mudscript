  
// by lys
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string about_sec();
string about_jail();
string about_lotch();
void create()
{
        set_name("趙青雲", ({ "chao ching yun","ching yun","yun" }) );
        set("gender","男性");
        set("age",25);
        set("int",40);
        set("inquiry", ([
                "秘密" : (: about_sec   :),
                "石牢" : (: about_jail  :),
                "寶藏" : (: about_lotch :),
                ]) );
        setup();
}
void init()
{
object me = this_player();
if(me->query_temp("poison_help") == 3) {
        remove_call_out("greeting");
        call_out("greeting",1,me);
       }
}
string about_lotch()
{
  object me = this_player();
  if( me->query_temp("poison_help") < 3 )
        return "我不知道你在說些什麼呀! ";
  command("say 曾有一魔教徒到金刀門為此魔教教主取得一寶物。");
  command("say 然因私藏寶物被捕入獄，曾被關在對面牢裡。");
  return "還說過箱底有寶什麼的，真搞不懂是怎麼一回事。";

}
string about_jail()
{
  object me = this_player();
  if( me->query_temp("poison_help") < 3 )
        return "我不知道你在說些什麼呀! ";
  command("say 其實進入石牢並不一定要磁石不可。");
  command("say 只要按那聖火像(fire)即可。");
  return "只要你讓我母親放心時，你就會明白按法。";
}
string about_sec()
{
  object me = this_player();
  if( me->query_temp("poison_help") < 3 )
        return "我有說過要告訴你秘密嗎?" ;
  command("say 我知道石牢和寶藏兩種秘密。");
  return "不知你要問何種秘密。";
}
void greeting(object me)
{
  object jade = new(POISON_OBJ"jade");
  me->set_temp("poison_help",4);
  command("smile");
  command("say 謝謝你來救我，我另有急事要辦，無法馬上回家。");
  command("say 這玉珮\煩請轉教我母親大人，她會知到我已平安。");
  jade->move(me);
}
