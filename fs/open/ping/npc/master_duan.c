// 段家 掌門人
//新增奧義之迷 by xboy
#include "/open/open.h"
#include <ansi.h>
int exert_sunforce();
inherit NPC;
inherit F_MASTER;
string do_thief();
string do_scar();
string do_chao();
string do_firecracker();
string do_sixfingers();
string do_tailong();
string do_trouble();
string do_chun();
string do_help();
string do_mark();
string do_mime();
string do_fan();
void add_record(string arg);
#define  RECORD        "/u/b/bss/recode"
string bad_man,record;
void create()
{
        set_name("段雲",({"lord duan","lord","duan"}));
        set("long","段雲便是當今皇上冊封的平南王, 同時也是段家武學的第十代傳人, "+
"雖然貴為王爺, 自有一肚子的墨水, 但其一身祖傳的武學卻也沒忘, 可說是文武雙全, "+
"也因為如此, 段雲自是非常重視文學素養, 若想拜入段家武學的門下, 則非是一位書生不可。\n");
        set("gender","男性");
        set("class","scholar");
        set("nickname","平南王");
        set("combat_exp",2000000);
        set("attitude","heroism");
        set("age",50);
        set("max_kee",5000);
        set("str", 44);
        set("cor", 24);
        set("cps", 45);
        set("per", 30);
        set("int", 42);
        set("inquiry", ([
        "thief"         : (: do_thief :),
        "scar"          : (: do_scar :),
        "sad_story"     : "若你不知道其中緣由,就不要再問了。",
        "chao"          : (: do_chao :),
        "firecracker"   : (: do_firecracker :),
        "一陽心法秘笈"  : "這一陽心法的秘笈聽說已由柳毅風尋獲, 只是不知他何時回來。",
        "六脈神劍"      : (: do_sixfingers :),
        "天龍寺"        : (: do_tailong :),
        "亂子"          : (: do_trouble :),
        "延慶太子"      : (: do_chun :),
        "急事"          : (: do_help :),
        "本因方丈"      : (: do_mark :),
        "六脈神劍經"    : "為本派武功\『六脈神劍』精要所在之武學寶典, 裡面紀載了連我都不知的『奧義』絕學。",
          "飄陽扇"        : (: do_fan :),
          "段霾"          : (: do_mime :),
        ]));
        set("force",3000);
        set("max_force",3000);
  set("six_spsp",1);
        set("force_factor", 20);
        set_skill("cure", 60);
set("no_lyssa",1);
        set_skill("dodge", 70);
        set_skill("force",80);
        set_skill("move", 70);
        set_skill("parry", 70);
        set_skill("stabber",120);
        set_skill("unarmed",20);
        set_skill("literate",120);
        set_skill("sunforce",80);
        set_skill("linpo-steps",100);
        set_skill("six-fingers",100);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","six-fingers");
        map_skill("stabber","six-fingers");
        map_skill("unarmed","six-fingers");
        set("functions/handwriting/level",100);
        set("marks/sun-finger",1);
        set("marks/six_sp",3);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action("stabber.handwriting") :),
        }));
        setup();
        carry_object(PING_OBJ"neck0")->wear();
  carry_object(PING_OBJ"cloud_fan");
        add_money("gold",10);
        create_family("段家",10,"掌門人");
}

void init()
{
        add_action("do_answer","answer");
       add_action("do_title","show_fan_to_duan");
        set_heart_beat(1);
}
void heart_beat()
{
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
                if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
        }
        }
        :: heart_beat();
}

string do_thief()
{
        object me=this_player();
        if( me->query_temp("thief") < 4 )
          return("京城的大盜..嗯..與我段家有關嗎﹖");
        else
        {
          command("sigh");
          return("唉..沒想到..他..唉..");
        }
}
string do_scar()
{
        object me=this_player();
        if( me->query_temp("thief") >= 3 )
        {
        if( me->query_temp("thief") == 3 )      me->set_temp("thief",4);
          return("大盜的右耳後有一小傷痕, 且使的是段家的\\武\\功\嗎﹖難道..難道是他..\n\n"+
          "段雲陷入深深的沈思之中, 似乎在回想著什麼。\n\n"+
          "段雲抱歉的說道: 我不想再提起這段傷心往事(sad_story)了。來人啊,送客..");
        }
        else
          return("啥..誰的傷痕﹖");
}
string do_chao()
{
        object me=this_player();
        object key=new(PING_OBJ"key0");
        if( me->query_temp("thief") >= 5 )
        {
          if( me->query_temp("thief") == 5 )    me->set_temp("thief",6);
          command("say 唉..你也知道了這件事了啊..是柳毅風跟你說的吧..其實過了"+
          "這麼多年, 我也該面對現實了。趙琴風變成京城大盜, 也算是段家管"+
          "教不周所致, 現在要引出趙琴風, 只有一個辦法, 就是用我們段家獨"+
          "門的聯絡煙火, 他看到了煙火必定會出現。");
          message_vision("$N交給$n一把鐵鑰匙。\n",this_object(),me);
          key->move(me);
          return("這是我們段家儲藏室的鑰匙, 你可以在那找到聯絡用的炮仗");
        }
}
string do_firecracker()
{
        object me=this_player();
        if( me->query_temp("thief") >= 6 )
        {
          if( me->query_temp("thief") == 6 )    me->set_temp("thief",7);
          return("啊..抱歉忘了說明炮仗的使用方法, 這炮仗需要在高地燃放才行, "
          +"且在燃放前要先︿＆％︿＊＆＠＃....明白了吧。");
        }
        else
          return("疑..你怎會知道這這炮仗的事, 給我老實道來!!");
}

//新增飄陽扇..........by dhk
string do_fan()
{
        object me=this_player();
        if( me->query_temp("buy_ok") == 1 )
        {
        if( me->query("family/family_name") == "段家" )      me->set_temp("fan",1);
          return("嗯!!你怎麼會知到飄陽扇﹖\n\n"+
          "段雲陷入深深的沈思之中，他說道：既然你問了那我就告訴你吧!\n\n"+
          "段雲接著說道：飄陽扇乃當年一位武器大師～北勝天大師替我們大理段氏\n"+
          "              所打造的一把傳說中的武器，因為其威力強大，所以向來\n"+
          "              只有段氏直系族人且品行優良者方能知曉，而在我們這一\n"+
          "              輩的，就是大師兄〔段霾〕了。\n");
        }
        else
          return("﹖");
}

//新增段霾.......by dhk
string do_mime()
{
        object me=this_player();
        object letter=new("/u/d/dhk/questsfan/obj/letter1.c");
        if( me->query_temp("fan") == 1 )
        {
          if( me->query("family/family_name") == "段家" )     me->set_temp("mime",1);
          command("say 唉!!!.......自從二十年前大師兄出走之後，就音訊全無。我曾數次派\n"+
          "          人去尋找，但全都無功\而返。這樣吧!!!!現下我就派你去尋找大師兄。\n"+
          "          而有關飄陽扇的事你也可以自己問他。但我怕大師兄會因事關武林安危\n"+
          "          而不告知。我這有一張拜帖，你拿給師兄，我想他應會回答你的問題。\n"+
          "\n");
          message_vision("$N交給$n一張拜帖。\n",this_object(),me);
          letter->move(me);
          return("你這次去尋大師兄，可得自己照顧自己。\n");
        }
        else
         return("?");
}

string do_sixfingers()
{
        object me=this_player();
        if( me->query("family/family_name")=="段家" && me->query("marks/six_sp")<=2)
        {
          me->set_temp("six_sp_quest",1);
          return("
              我大理段氏向來以一陽指與六脈神劍聞名, 那一陽指固然難練,
              六脈神劍更是百年難得有一人能盡得真傳, 因此『天龍寺』的高
              僧為延續此一神功\, 撰寫了一部『六脈神劍經』。");
        }
        else
        {
          command("kick"+me->query("id"));
          return("笨蛋!!玩那麼久的狂想還不知道六脈神劍, 去死算了!!");
        }
}

string do_tailong()
{
        object me=this_player();
        if( me->query_temp("six_sp_quest")==1)
        {
          me->set_temp("six_sp_quest",2);
          return("
              乃是我大理段氏的武學重鎮, 過去許\多的『亂子』都是有天龍寺
              高僧相助, 才得以渡過難關。");
        }
        else
          return("你問那麼多幹嘛...");
}

string do_trouble()
{
        object me=this_player();
        if( me->query_temp("six_sp_quest")==2)
        {
          me->set_temp("six_sp_quest",3);
          return("
              莫過於百餘年前的那場皇宮內亂, 當時『延慶太子』遭人圍攻,
              後來一度失蹤, 我先祖得到天龍寺眾高僧協助, 才得以平亂。");
        }
        else
          return("現在乃是太平盛世, 哪來的亂子??");
}

string do_chun()
{
        object me=this_player();
        if( me->query_temp("six_sp_quest")==3)
        {
          me->set_temp("six_sp_quest",4);
          return("
              此人原為我段家出類拔萃的人物, 奈何當年那場大亂, 竟
              使他投入邪派, 後來更成為四大惡人之首, 危害武林, 其
              武功\身兼正邪, 真的當者披靡, 不過這十多年來, 未再聽
              到其消息, 想是已不在人世才是。");
        }
        else
          return("什麼『鹽浸太久』??拜託你說國語好不好!");
}

string do_help()
{
        object me=this_player();
        if( me->query_temp("six_sp_quest")==5)
        {
          me->set_temp("six_sp_quest",6);
          return("
              延慶太子原來還在人間, 這次更闖進天龍寺, 盜走六脈神劍經,
              徒兒, 為師派你去天龍寺相助『本因方丈』, 務必把寶經奪回!!");
        }
        else
          return("啥?你尿急喔?出門左轉第二間就是廁所, 不用謝我了。");
}

string do_mark()
{
        object me=this_player();
        object mark=new(PING_OBJ"tai_mark");
        if( me->query_temp("six_sp_quest")==6)
        {
          me->set_temp("six_sp_quest",7);
          command("say 本因方丈主持天龍寺多年, 你此去相見, 只須交給他信物, 他便知道了。");
          message_vision("$N交給$n一只天龍令。\n",this_object(),me);
          mark->move(me);
          return("快去吧!");
        }
        else
          return("本因坊是下圍棋的, 跟我沒有關係。");
}

int exert_sunforce()
{
        object ob=this_object();
        if( !present("sunforce finger",ob) )
        {
          command("say 好..老夫就陪你玩玩。");
          command("exert sun-finger");
          command("wield finger");
        }
        return 1;
}

int do_answer(string str)
{
        object me=this_player();
        string *answer = ({
        "虞兮虞兮奈若何",
        "去日苦多",
        "對影成三人",
        "悠然見南山",
        "春風不度玉門關",
        "西出陽關無故人",
        "共此燈燭光",
        "此恨綿綿無絕期",
        "千古風流人物",
        "一步江湖無盡期",
        "濁酒一杯笑紅塵",
        "竊竊暗笑世人癡",
        "神機妙算讚白蓮"
        });
        if(me->query_temp("answer") < 0);
        else
        {
          if(str == answer[me->query_temp("answer")])
          {
            command("pat "+me->query("id"));
            write("很好﹐" + RANK_D->query_respect(me) + "的文學底子不錯, 多加努力, "+
            "他日必能為段家發揚光大, 在江湖上揚名立姓。\n");
            command("recruit " + me->query("id") );
            me->set("startroom",environment(me));
            write("嗯..你的內功\不夠純正, 讓為師的助你一臂之力吧。\n");
            message_vision("段雲緩緩的伸出右手, 往$N頭頂的百會穴一按, 絲絲的蒸氣從$N的頭上冒了出來....。\n",me);
            me->improve_skill("sunforce",2);
            command("smile "+me->query("id"));
            write("好了, 為師已將一小部份的一陽心法傳與你, 望你能再接再勵, 終於大成。\n");
            CHANNEL_D->do_channel(this_object(), "chat",
            sprintf("%s成為段家的一員了, 希望大家能本著江湖精神照顧他。",me->name(1)));
          }
          else
          {
            command("sigh "+me->query("id"));
            write(RANK_D->query_respect(me)+"你的文學素養太淺了, 也許\應該多去品嚐書籍, "+
            "下次有把握了再來找我吧...\n");
          }
          me->delete_temp("answer");
        }
        return 1;
}

void attempt_apprentice(object me)
{
        int which;
        string *question = ({
        "項羽『核下歌』\n「力拔山兮氣蓋\世! 時不利兮騅不逝! 騅不逝兮可奈何! .......」",
        "曹操『短歌行』\n「對酒當歌, 人生幾何? 譬如朝露, ....」",
        "李白『月下獨酌』\n「花間一壺酒, 獨酌無相親; 舉杯邀明月, .....」",
        "陶淵明『飲酒』\n「結盧在人間, 而無車馬喧。問君何能爾, 心遠地自偏。採菊東離下, .....。」",
        "王之渙『涼州詞』\n「黃河遠上白雲間, 一片孤城萬仞山。羌笛何須怨楊柳, .......。」",
        "王維『渭城曲』\n「渭城朝雨浥清塵, 客舍青青柳色新。勸君更進一杯酒, .......。",
        "杜甫『贈衛八處士』\n「人生不相見, 動如參與商。今夕復何夕, .....」",
        "白居易『長恨歌』\n「在天願做比翼鳥, 在地願為連理枝。天長地久有時盡, .......!",
        "大江東去, 浪淘盡, ......」",
        "錦鯉欲躍龍門池, 北風一動離水時, 戰火燒斷逍遙夢.......",
        "世事如棋局局新, 豪傑似浪翻不盡, 古往今來多少事.......",
        "還真為逐青雲志, 一生真偽有誰知, 堂堂滿言仁義情.......",
        "靈車赫赫天下驚, 妖聲邪氣瀰滿天, 金葉一動清香現......."
        });
        which=random(sizeof(question));
        if(me->query_temp("have_apprentice"))
          write("怎麼這麼快又見面了? 下次再來吧。\n");
        else
        {
        write(" "+RANK_D->query_respect(me)+"想拜入我的門下嗎? 我門的內功\首重內心修養, "+
        "若學識沒有一定的基礎, 對自身反而有害。老夫這就來試一試你, 若真心想學的話就回答(answer)我的問題吧\n");
write("段雲緩緩的吟唱道:"+question[which]+"\n");
        write("段雲和藹的說道: 你能說說接下來的句子嗎?\n");
        me->set_temp("have_apprentice",1);
        me->set_temp("answer",which);
        }
}
int accept_object(object me, object obj)
{
        if( obj->query("name") == "一陽心法秘笈" )
        {
          command("pat "+getuid(me));
          command("say 太好了, 是柳毅風託你的嗎﹖謝了。");
          if( me->query("family/family_name") == "段家" && !me->query("marks/sun-finger") )
          {
            command("say 既然你護送秘笈有功\, 我便將此秘笈上記載的絕招傳授與你吧。");
            write(this_object()->query("name")+"看著秘笈隨手演練一遍。\n\n"+
            "你覺得心中疑慮豁然貫通, 全身內力迅速流轉一周天。\n\n"+
            "你的內力值達到上限了。\n\n"+
            "你學會了一陽心法中的絕招「化氣為筆」。\n\n");
            if( me->query("force") < me->query("max_force") )
              me->set("force",me->query("max_force"));
            me->set("marks/sun-finger",1);
          }
          destruct(obj);
        }
        else
        {
        command("? "+getuid(me));
        record="";
        record=getuid(me)+"給了段雲一個"+obj->query("name")+"在"+ctime(time())+"。";
        add_record(record);
        bad_man=getuid(me);
        }
        return 1;
}

void add_record(string arg)
{
        string  *oldlist, newlist;
        int i;

        newlist="";
        oldlist=explode(read_file("/u/b/bss/record"),"\n");
        for(i=0;i<sizeof(oldlist);i++){
        newlist+=oldlist[i]+"\n";
        }
        newlist+=arg+"\n";
        rm("/u/b/bss/record");
        write_file("/u/b/bss/record", newlist);
        return ;
}
void die()
{
        object winner = query_temp("last_damage_from");
        if(!wizardp(winner)){
        tell_object(users(),"\n\t『天下風雲出我輩  一入江湖歲月摧\n\t\t皇圖霸業談笑中  不勝人生一場醉』\n"+
        "\n\t想我段雲縱橫江湖, 今日敗於"+winner->query("name")+"之手\n\t可謂  時也～  運也～  命也～\n");
        tell_object(users(),"\n\n南方天空畫過一道流星。\n\n\t「天機星落」\n\n");
        }
        :: die();
}
int accept_kill(object who)
{

        who=this_player();
        if(who->query("id")==bad_man)
        {
        record="";
        record=getuid(who)+"可能利用作弊的方法殺死段雲在"+ctime(time())+"。";
        add_record(record);
        }
        command("unwield all");
        command("wield fan");
        command("kill "+who->query("id"));
        command("exert sun-finger");
        command("perform unarmed.handwriting");
        command("wield finger");
        return 1;
}
int accept_fight(object who)
{
        who=this_player();
        if(who->query("id")==bad_man)
        {
        record="";
        record=getuid(who)+"可能利用作弊的方法殺死段雲在"+ctime(time())+"。";
        add_record(record);
        }
        command("unwield all");
        command("wield fan");
        command("exert sun-finger");
        fight_ob(who);
        command("perform unarmed.handwriting");
        command("wield finger");
        return 1;
}
int do_title()
{
  object me=this_player();
  if(!me->query("make_ok"))
  {
if(me->query("gender")=="男性")
{
me->set("title","" + HIY + "文凌駕" + NOR + "『" + HIC + "飄" + NOR + "陽" + HIC + "靈" + NOR + "帝』");
  me->set("make_ok",1);
tell_object(me,"你做的不錯，好扇、好扇呀！...哈哈哈　!!!\n");
}
else
{
me->set("title","" + HIM + "文翎羽" + NOR + "『" + HIY + "玄" + NOR + "天" + HIY + "靈" + NOR + "后』");
  me->set("make_ok",1);
tell_object(me,"你做的不錯，好扇、好扇呀！...哈哈哈　!!!\n");
}
}
else
tell_object(me,"閣下已經改過title了。\n");
  return 1;
}
