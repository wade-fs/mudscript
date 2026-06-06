//sheik.c
#include <ansi.h>
inherit NPC;
string sun12();
string sun13();
string sun14();
string sun15();
void create()
{
	set_name("張鐵匠",({"smith chang","smith","chang"}) );
	set("long","精於兵器打造的鐵匠，但個性相當暴躁，對於「后羿」的要求相當不耐煩。\n");
	set("gender","男性");
	set("age",51);
	set("combat_exp", 23);
	set("inquiry",([
	"后羿":(: sun12 :),
	"做箭":(: sun13 :),
	"稀有礦石":(: sun14 :),
	"天地靈氣":(: sun15 :),
	]));
	setup();
}

string sun12()
{
 object me = this_player();
 int k;
 k = me->query_temp("ask-break-sun");
 if(!me) return"";
 if(me->query("family/family_name") != "射日派") return "聽不懂啦!!";
 if(k>11) return "你是要問幾次啦!?";
 if(me->query("break-sun")) return "你和他一起射下太陽，真是感謝了!!";
 if(!k || k<11) return "不知道啦!!";
 else {
       command("hmm");
       command("say 
你說的是那個成天站在山崖上想射太陽的阿呆喔？兩年前被他矇到擊落了一顆，
此後就沒再射下過了，當初還找我做箭，作出一堆詭異的箭矢，真不曉得他腦袋
裡到底在想些什麼。");
       me->set_temp("ask-break-sun",12);
      }
  return "";
}

string sun13()
{
 object me = this_player();
 int k;
 k = me->query_temp("ask-break-sun");
 if(!me) return"";
 if(me->query("family/family_name") != "射日派") return "聽不懂啦!!";
 if(k>12) return "箭!!";
 if(me->query("break-sun")) return "我做出來的箭能派上用場，真是太好了!!";
 if(!k || k<12) return "請不要作賤自己!!";
 else {
       command("kick");
       command("say 我們偶然間才找到一小塊罕見的稀有礦石，全作成箭矢給那小子拿去玩了!!");
       me->set_temp("ask-break-sun",13);
      }
  return "";
}

string sun14()
{
 object me = this_player();
 int k;
 k = me->query_temp("ask-break-sun");
 if(!me) return"";
 if(me->query("family/family_name") != "射日派") return "聽不懂啦!!";
 if(k>13) return "這麼好的礦石居然拿去作箭，可惜了!!";
 if(me->query("break-sun")) return "你真是太厲害了，說找到就找到!!";
 if(!k || k<13) return "不知道啦!!";
 else {
       command("sigh");
       command("say 
那是由構成這世界的最重要物質，長年吸收天地靈氣之後轉化而成的，據
說在各地都或多或少散布著，大多是粉末，偶爾可以看到較完整的碎片。");
       me->set_temp("ask-break-sun",14);
      }
  return "";
}

string sun15()
{
 object me = this_player();
 int k;
 k = me->query_temp("ask-break-sun");
 if(!me) return"";
 if(me->query("family/family_name") != "射日派") return "聽不懂啦!!";
 if(k>14) return "這麼好的礦石居然拿去作箭，可惜了!!";
 if(me->query("break-sun")) return "你真是太厲害了，說找到就找到!!";
 if(!k || k<14) return "不知道啦!!";
 else {
       command("think");
       command("say 
山崖邊有座山神廟，自古以來匯聚著天地靈氣，我們就是在那裡發現的，傳說將東西放在那裡可以吸收天地靈氣，
若想拿來射太陽，至少也得吸收十甲子的時間，但現在我們都快要被烤死了，哪等得到那麼久呢。。");
       me->set_temp("ask-break-sun",15);
      }
  return "";
}

int accept_object(object me,object ob)
{
 int k;
 me = this_player();
 k = me->query_temp("ask-break-sun");
 if(!ob || !me) return 0;
 if(!k || k!=18) command("say 太好了!!");
 else if(k == 18 && ob->query("id") == "color-stone")
 {
  command("wa");
  command("say 真是了不得啊年輕人!!這五彩礦石可是十甲子才出現一次的，沒想到你竟能取來。");
  command("say 好！看在你這傢伙有個真材實料，老子這就卯起來幫你做了！");
  destruct(ob);
  me->start_busy(9);
  call_out("do_givearrow",9,me);
 } else command("say 太好了!!");
 return 1;
}

int do_givearrow()
{
 int k;
 object arrow,me;
 me = this_player();
 if(!me) return 0;
 k = me->query_temp("ask-break-sun");
 if(!k || k!=18) return 0;
 else {
  command("sweat");
  command("say 哪！好啦！快拿去吧，希望這箭真能夠再次射下太陽，解救天下蒼生。");
  arrow = new("/open/marksman/break-sun/obj/color-arrow");
  arrow->set_amount(500);
  arrow->move(me);
  me->set_temp("ask-break-sun",19)  ;
      }
  return 1;
}
