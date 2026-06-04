// natured.c

#include <obj.h>
#include <ansi.h>
#include <login.h>
#define INTERMAIL_I "/data/intermail_i"
static int current_day_phase = 0;
static int current_weather=0;
static int c=0;
static int weather_hurt=0, weather_light=1;

mapping *day_phase;
mapping *weather;

mapping *read_table(string file);
void init_day_phase();
void init_weather();
void check_heart_beat();

int     clan_30min, clan_1hr, clan_2hr, clan_12hr;
void    clan();

void auto_reboot();
void sp_boss();
void init_mail();
void sys_init(int start);
void war_start();
void do_full();
void three_evil();

int reboot_flag=0;

void create()
{
        day_phase = read_table("/adm/etc/nature/day_phase");
        init_day_phase();

        weather = read_table("/adm/etc/nature/weather");
        // ... code without SEND_MONEY ...
                clan();
                init_mail();
                auto_reboot();
        	war_start();
                do_full();
                sp_boss();
//                sys_init(-1);
                //call_out( "check_heart_beat", 10 );
        }

// /*
void init_mail()
{
  mapping       cont;
  object        mailbox;
  string        mail, *mails;
  string        from, to;
  int           i, j, k;
  mail = read_file (INTERMAIL_I);
  if (!mail) mail = "";
  rm (INTERMAIL_I);
  mails = explode (mail, "\n");

  for (i=1; i<sizeof (mails); i++) {
    if (j == 0) {
      if (mails[i-1][0..8] == "#mailto: " && mails[i][0..10] == "#mailfrom: ") {
        j = 1;
        k = i+1;
        from = mails[i][11..<1];
        to = mails[i-1][9..<1];
      }
    }
    else if (j == 1) {
      if (mails[i-1][0..8] == "#mailto: " && mails[i][0..10] == "#mailfrom: ") {
        mail = implode (mails[k..i-2], "\n");
        mail = ">>> 這是一封來自網際網路的信, 如果要回信, 請寄到:\n>>> "+
               from+"\n>>> 回信請用 imail 命令.\n"+mail;
        seteuid (ROOT_UID);
        mailbox = new (MAILBOX_OB);
        cont = ([
          "from"        : from,
          "title"       : "網際網路信件",
          "to"          : to,
          "text"        : mail,
        ]);
        mailbox->send_mail (to, cont);
        destruct (mailbox);
        k = i+1;
        from = mails[i][9..<1];
        to = mails[i-1][9..<1];
      }
      else if (i == sizeof (mails)-1) {
        mail = implode (mails[k..i], "\n");
        mail = ">>> 這是一封來自網際網路的信, 如果要回信, 請寄到:\n>>> "+
               from+"\n"+mail;
        seteuid (ROOT_UID);
        mailbox = new (MAILBOX_OB);
        cont = ([
          "from"        : from,
          "title"       : "網際網路信件",
          "to"          : to,
          "text"        : mail,
        ]);
        mailbox->send_mail (to, cont);
        destruct (mailbox);
      }
    }
  }

  call_out ("init_mail", 288);
}

//用來放在開機時需要乎叫的code
varargs void sys_init(int start)
{
        mixed *files;
        string dir;
        int i,len;
   
        dir="/daemon/skill/";
        files=get_dir(dir,-1);
        if(start == -1 ) i=sizeof(files);
        else i = start;
        while(i--)
        {
          len=sizeof(files[i][0]);
          if(files[i][0][len-2..len-1]!=".c")
            continue ;
          load_object(dir+files[i][0]);
          if(i%30 == 0 ) {
            //      call_out("sys_init", 1, -1);

            break;
          }
        }
}

/*void find_robot()
{
        int     i;
        object  *user;

        if( ((time()+28800)%86400) < 28800 ) {
                call_out( "find_robot", 300+random(1500) );
                return;
        }

        remove_call_out("robot_ans");
        remove_call_out("find_robot");
        user = users();
        for( i=0; i<sizeof(user); i++ ) {
                if(     wizardp(user[i])                        || // 巫師
                        user[i]->is_fighting()                  || // 戰鬥
                        user[i]->query_temp("pk_fight")         || // pkla
                        user[i]->query_temp("unconcious")==1    || // 暈倒
                        user[i]->query_temp("netdead")          || // 斷線
                        (query_idle(user[i])/60) > 1            || // 發呆
                        user[i]->is_ghost()                     || // 鬼魂
                        random(2)==1                            || // 50%
                        !user[i]->query("id")                      // login
                        )
                        continue;
                if(     in_edit(user[i]) || // 編輯
                        in_input(user[i])){ // 閱讀
                  user[i]->set_temp("wait_ask",1);
                  continue;
                }
                ask_question(user[i]);
        }
        call_out( "robot_ans", 180 );
        call_out( "find_robot", 300+random(1500) );
}
void ask_question(object ppl)
{
    int ans;
    if(!ppl) return ;
    ans = random(100000) + 1;
    tell_object( ppl,
            HIW + "\n***************************************************************\n" +
            HIW + "\n\t系統要清查機器人, 請回答下面問題:\n"+
            HIW + "\n***************************************************************\n");
    tell_object( ppl,
            sprintf("『請用 ans 回答以下是甚麼數字？』\n%s", paper(""+ans)) );
    ppl->set( "robot/ans", ""+ans );
    tell_object( ppl,
            HIW+"***************************************************************\n" + NOR);
}
void robot_ans()
{
        int     i;
        object  *user;

        remove_call_out("robot_ans");
        user = users();
        for( i=0; i<sizeof(user); i++ ) {
                if(     user[i]->is_fighting()                  || // 戰鬥
                        user[i]->query_temp("pk_fight")         || // pkla
                        user[i]->query_temp("unconcious")==1    || // 暈倒
                        user[i]->query_temp("netdead")          || // 斷線
                        (query_idle(user[i])/60) > 1            || // 發呆
                        user[i]->is_ghost()                     || // 鬼魂
                        !user[i]->query("robot/ans")               // login
                        )
                        continue;
                if(     in_edit(user[i]) ||// 編輯
                        in_input(user[i])){// 閱讀
                        user[i]->set_temp("wait_get",1);
                        continue;
                }
                get_robot(user[i]);
        }
}
void get_robot(object ppl)
{
    if(!ppl) return ;
    tell_object( ppl, "你已經沒有機會回答問題。\n" );
    ppl->move("/open/wiz/jail.c");
    if( !ppl->query("jail_time") ) {
            ppl->set( "jail_time", ppl->query("mud_age")+60*10 );
            return ;
    }
    ppl->set( "jail_time", ppl->query("jail_time")*2-ppl->query("mud_age") );
    if( ppl->query("jail_time")-ppl->query("mud_age")>60*60*12 )
            ppl->set( "jail_time", ppl->query("mud_age")+60*60*12 );
}
*/
void clan()     //幫派的時間判斷
{
        int period, time, now = uptime();

        period = 1800;        //per 30 min
        time = now+period/2;
        if( time/period > clan_30min ) {
                CLANV_D->clan_log();
                clan_30min = time/period;
        }

        period = 3600;        //per 1 hour
        time = now+period/2;
        if( time/period > clan_1hr ) {
                CLANV_D->clan_tax();
                clan_1hr = time/period;
        }

        period = 7200;        //per 2 hour
        time = now+period/2;
        if( time/period > clan_2hr ) {
                CLANV_D->clan_cost();
                CLANV_D->clan_develop();
                clan_2hr = time/period;
        }

        period = 43200;        //per 12 hour
        time = now+period/2;
        if( time/period > clan_12hr ) {
                CLANV_D->clan_prestige();
                clan_12hr = time/period;
        }

        call_out( "clan", 600 );
}


void auto_reboot()
{
        object npc;
        //when 7'clock reboot
        //我只會用笨方法by bss
        if(uptime() > 4000 && (ctime(time())[11..12]=="07" ||
                               ctime(time())[11..12]=="19" )) {
                npc = new(NPC_DEMOGORGON);
                npc->move(REBOOT_PLACE);
                npc->start_shutdown(3);
                call_out("three_evil",160);
        }
        else call_out("auto_reboot",60 );
}

void three_evil()
{
   object mob1,mob2,mob3;
   int i;
   i=random(3);
   mob1 = new("/open/dancer/npc/wind-fighter");
   mob2 = new("/open/dancer/npc/wild-blader");
   mob3 = new("/open/dancer/npc/fly-dancer");
   mob1->set_temp("roared",1);
   mob2->set_temp("roared",1);
   mob3->set_temp("roared",1);
   mob1->set_temp("no_die_soon",1);
   mob2->set_temp("no_die_soon",1);
   mob3->set_temp("no_die_soon",1);
   shout(
HIG + "南方三霸" + HIM + "狂笑道：\n"+
                          HIY + "隱居南蠻苦練數載，今日應是我們報仇的時刻了！哈哈哈！！！\n\n"+
                                                  "\t\t\t\n\n" + NOR);

if (i==0)
{
 mob1->move("/open/prayer/room/punch1-5");
 mob2->move("/open/port/room/r4-7");
 mob3->move("/open/dancer/room/roomen1");
}
else if (i==1)
{
 mob1->move("/open/north-polar/room27");
 mob2->move("/open/ping/questsfan/rm8");
 mob3->move("/open/tendo/room/t03");
}
else 
{
 mob1->move("/open/gblade/mrm/room/class/r10");
 mob2->move("/open/dancer/room/yuaroom");
 mob3->move("/open/tendo/kunlun/cloud");
}
}

void war_start()
{
	string *f1,*m1,*d1,*s1,*pp,*M1,*L1,*F1,*mg;
	string p1,p2,p3,p4,p5,p6,p7,p8,p9,pmgd,pm01,pm02,pm03,pm04,pm05,pm06,pm07,pm08,pm09,pm10,pm11,pm12;
	int c2,i;
	object *mob;
	c2 = random(10);
	i  = random(3);
	f1 = get_dir("/open/main/room/f*.c");
	m1 = get_dir("/open/main/room/m*.c");
	d1 = get_dir("/open/main/room/d*.c");
	s1 = get_dir("/open/main/room/s*.c");
	F1 = get_dir("/open/main/room/F*.c");
	M1 = get_dir("/open/main/room/M*.c");
	L1 = get_dir("/open/main/room/L*.c");
	pp = get_dir("/open/main/room/p*.c");
	mg = get_dir("/open/magic-manor/manor*.c");
	
	p1 = "/open/main/room/"+f1[random(sizeof(f1))];
	p2 = "/open/main/room/"+m1[random(sizeof(m1))];

	p4 = "/open/main/room/"+s1[random(sizeof(s1))];
	p5 = "/open/main/room/"+d1[random(sizeof(d1))];
	p6 = "/open/main/room/"+L1[random(sizeof(L1))];
	p7 = "/open/main/room/"+M1[random(sizeof(M1))];

	p8 = "/open/main/room/"+pp[random(sizeof(pp))];
	p9 = "/open/main/room/"+F1[random(sizeof(F1))];

	pmgd = "/open/magic-manor/"+mg[random(sizeof(mg))];
	pm01 = "/open/magic-manor/"+mg[random(sizeof(mg))];
	pm02 = "/open/magic-manor/"+mg[random(sizeof(mg))];
	pm03 = "/open/magic-manor/"+mg[random(sizeof(mg))];
	pm04 = "/open/magic-manor/"+mg[random(sizeof(mg))];
	pm05 = "/open/magic-manor/"+mg[random(sizeof(mg))];
	pm06 = "/open/magic-manor/"+mg[random(sizeof(mg))];
	pm07 = "/open/magic-manor/"+mg[random(sizeof(mg))];
	pm08 = "/open/magic-manor/"+mg[random(sizeof(mg))];
	pm09 = "/open/magic-manor/"+mg[random(sizeof(mg))];
	pm10 = "/open/magic-manor/"+mg[random(sizeof(mg))];
	pm11 = "/open/magic-manor/"+mg[random(sizeof(mg))];
	pm12 = "/open/magic-manor/"+mg[random(sizeof(mg))];

	if(c2 <= 5)  p3 = "/open/main/room/"+pp[random(sizeof(pp))];
	else if(c2==6) p3 = "/open/gblade/navy/room/d1-1";
	else if(c2==7) p3 = "/open/capital/room/r70";
	else if(c2==8) p3 = "/open/capital/room/r25";
	else  p3 = "/open/magic-manor/town/town05";
//if(find_player("whatup")) tell_object(find_player("whatup"),sprintf("p1:%s\np2:%s\np3:%s\np4:%s\np5:%s\np6:%s\n",p1,p2,p3,p4,p5,p6));
//return ;
 if(uptime() > 3600 && (ctime(time())[11..12]=="10" ||
                               ctime(time())[11..12]=="22" )) {
string cp;
string *place = ({ "/open/capital/room/r08",
"/open/capital/room/tower","/open/capital/room/r11","/open/capital/room/r70"
,"/open/capital/room/D04",
});
	shout(HIG + "\n狂想空間北邊關卡附近傳來一聲淒慘的哀嚎聲\n\n"+
HIR + "鎮國侯奄奄一息的說道：\n\n"+
                             "臣鎮守邊關數十年，誓死保衛國家太平\n"+
                             "如今邊關被破，臣有負皇上重託，唯有一死以謝天下\n\n"+
HIY + "神秘劍客冷笑道：\n"+
                          HIC + "流放邊疆數十年，如今讓我們重回中土，看來天下又要大亂了！哈哈哈！！！\n\n"+


HIB + "黃帝病大怒：\n"+
                          HIM + "哼！只要有我在的一天，你們這些叛徒就休想染指中原！\n\n"+


HIG + "天威滅神大笑：\n"+
                          HIW + "藏身天界數千年的歲月，終於等到自由的這一刻，十二天靈狩們與我一同創造這世界的新秩序吧！\n\n"+
						  "\t\t\t\n\n" + NOR);

if (i==0)
{
	new("/open/dancer/npc/knight")->move(p1);
	new("/open/dancer/npc/shooter")->move(p2);
	new("/open/dancer/npc/knight")->move(p3);
	new("/open/dancer/npc/knight")->move(p4);
	new("/open/dancer/npc/shooter")->move(p5);
	new("/open/dancer/npc/knight")->move(p6);
	new("/open/dancer/npc/knight")->move(p7);
	new("/open/dancer/npc/shooter")->move(p8);
	new("/open/dancer/npc/knight")->move(p9);
	new("/open/dancer/npc/knight")->move(p1);
	new("/open/dancer/npc/shooter")->move(p4);
	new("/open/dancer/npc/knight")->move(p6);
	new("/open/sky/npc/damp_god.c")->move(pmgd);
	new("/open/sky/npc/obj-god06.c")->move(pm06);
	new("/open/sky/npc/obj-god10.c")->move(pm10);
	new("/open/sky/npc/obj-god11.c")->move(pm11);
	new("/open/sky/npc/obj-god12.c")->move(pm12);
}
else if (i==1)
{
	new("/open/dancer/npc/knight")->move(p1);
	new("/open/dancer/npc/shooter")->move(p2);
	new("/open/dancer/npc/knight")->move(p3);
	new("/open/dancer/npc/knight")->move(p4);
	new("/open/dancer/npc/shooter")->move(p5);
	new("/open/dancer/npc/knight")->move(p6);
	new("/open/dancer/npc/knight")->move(p7);
	new("/open/dancer/npc/shooter")->move(p8);
	new("/open/dancer/npc/knight")->move(p9);
	new("/open/sky/npc/damp_god.c")->move(pmgd);
	new("/open/sky/npc/obj-god06.c")->move(pm06);
	new("/open/sky/npc/obj-god10.c")->move(pm10);
	new("/open/sky/npc/obj-god11.c")->move(pm11);
	new("/open/sky/npc/obj-god12.c")->move(pm12);
	call_out("three_evil",1);
}
else
{
	new("/open/dancer/npc/knight")->move(p1);
	new("/open/dancer/npc/shooter")->move(p3);
	new("/open/dancer/npc/knight")->move(p2);
	new("/open/dancer/npc/knight")->move(p5);
	new("/open/dancer/npc/shooter")->move(p4);
	new("/open/dancer/npc/knight")->move(p6);
	new("/open/dancer/npc/knight")->move(p1);
	new("/open/dancer/npc/shooter")->move(p2);
	new("/open/dancer/npc/knight")->move(p3);
	new("/open/dancer/npc/knight")->move(p4);
	new("/open/dancer/npc/shooter")->move(p5);
	new("/open/dancer/npc/knight")->move(p6);
	new("/open/sky/npc/damp_god.c")->move(pmgd);
	new("/open/sky/npc/obj-god06.c")->move(pm06);
	new("/open/sky/npc/obj-god10.c")->move(pm10);
	new("/open/sky/npc/obj-god11.c")->move(pm11);
	new("/open/sky/npc/obj-god12.c")->move(pm12);
}

// let's they auto move
children("/open/dancer/npc/knight")->heart_beat();
children("/open/dancer/npc/shooter")->heart_beat();
cp = place[random(sizeof(place))];
 log_file("tree",sprintf("[%O] tree must in %s\n",""+time(),cp));
new("/open/capital/npc/tree")->move(cp);
   }
   else call_out("war_start",300);
}
void do_full()
{ 
  int i;
  object *user;
  user = users();
  if( ((time()+28800)%86400) < 28800 ) {
                call_out( "do_full", 3600+random(7200) );
                return;
        }
   message( "system",HIY+"你發現傅劍寒突然騎著五爪金龍出現在半空中。\n"+NOR , users() );
   message( "system",HIW+"只見傅劍寒唸了一句 撒拉 伊克 庵修姆。\n"+NOR, users());
   message( "system",HIM+"你忽然覺得精神百倍，信心大增。\n"+NOR, users());
   for( i=0; i<sizeof(user); i++ ) {
   user[i]->set("eff_gin",user[i]->query("max_gin"));
   user[i]->set("gin",user[i]->query("max_gin"));
   user[i]->set("eff_kee",user[i]->query("max_kee"));
   user[i]->set("kee",user[i]->query("max_kee"));
   user[i]->set("eff_sen",user[i]->query("max_sen"));
   user[i]->set("sen",user[i]->query("max_sen"));
   }
   call_out( "do_full", 3600+random(7200) );
}




void sp_boss()
{
        object npc1,npc2,npc3;

        if( uptime() > 34800 ) {
            shout(HIC + "\n陣陣天驚地動... 英雄魂之道的武士們現世了\n\n"+
   "\t     其手中的劍向天下發出強勢氣壓..\n"+
   "\t只見他傲視全狂想的一片大地, 感嘆無人為其十合之眾\n"+
   "\t狂想的勇士們來挑戰他吧～～～～\n\n"+
   "\t\t\t\n\n" + NOR);

            npc1 = new("/u/a/anmy/king/pope");
            npc2 = new("/u/a/anmy/king/master_teng");
            npc3 = new("/u/a/anmy/king/master_ba");
            npc1->move("/open/center/room/road1");
            npc2->move("/open/center/room/road1");
            npc3->move("/open/center/room/road1");
        }
        else call_out("sp_boss", 3600);
}


//
// FS 發錢系統
// made by konn
//
void send_money()
{
        object *user;
        int i, money, t_money, sub;

        if( uptime()/(10800-150*sizeof(users())) > send_money_time ) {
//
            shout(HIY + "\n奉天承運, 皇帝召曰:\n\n"+
                  "\t宣  近日各地傳德政頻頻, 為獎賞各地父母官, 特加\n"+
                  "\t薪餉, 各地錢莊亦加 1% 利息, 以回饋各地武林好友。\n\n"+
                  "\t\t\t\t\t\t\t欽此\n\n" + NOR);
//
            send_money_time++;
            user = users();
            for(i=0; i<sizeof(user); i++) {
                if( !user[i]->query("id")          ||
                    wizardp(user[i])               ||
                    user[i]->query_temp("netdied") )
                    continue;
//
                if( !user[i]->query("bank/coin") ) {
                    user[i]->set("bank/coin", 50000);
                    continue;
                }

                money = 0;
                t_money = user[i]->query("bank/coin");
                t_money += t_money / 100;

                if( t_money >= 2000000000 ) {
                    user[i]->set("bank/coin",2000000000);
                }
                if( (t_money+money) <= 0 || (t_money+money) >= 2000000000 ) {
                    user[i]->set("bank/coin",2000000000);
                }
                else user[i]->set("bank/coin", money+t_money);

//
            }
//
            if( send_money_time % 5 == 0 )
                call_out("find_the_best", 30);
//
        }
        call_out("send_money", 60);
}

void find_the_best()
{
        object *user, best;
        int i;

        for(i=0; i<sizeof(user); i++) {
            if( !user[i]->query("id")          ||
                wizardp(user[i])               ||
                user[i]->query_temp("netdied") )
                continue;
            if( !best ) {
                best = user[i];
                continue;
            }
            if( user[i]->query("combat_exp") > best->query("combat_exp") )
                best = user[i];
        }
        shout(HIY + "㊣稅官㊣：恭喜FS最強的玩家"+HIW+best->name()+HIY+
              ", 由於受到皇上的賞識, 賞賜五十兩黃金及五百點潛能, "+
              "希望"+HIW+best->name()+HIW+"能夠繼續努力, 創造出更好"+
              "的成績。" + NOR);
        best->add("potential", 500);
        user[i]->pay_player(500000);
}

void init_day_phase()
{
        mixed *local;
        int i, t;

        // Get minutes of today.
        local = localtime(time()*60);
        t = local[2] * 60 + local[1];           // hour * 60 + minutes

        // Find the day phase for now.
        for( i=0; i < sizeof(day_phase); i++)
                if( t >= day_phase[i]["length"] )
                        t -= (int)day_phase[i]["length"];

        // Since in our time scale, 1 minute == 1 second in RL, so we don't need
        // any conversion before using this number as call_out dalay, if you
        // changed the time scale, be sure to convert it.

        call_out("update_day_phase",
                (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void init_weather()
{
        weather_light = 1;
        call_out("update_weather", (int)weather[1]["length"] + random(31)-15);
}

void update_weather()
{
        int             r, t, tt;

        weather_hurt = 0;

        remove_call_out("update_weather");
        if ( c > 0 || (c == -1 && random(4)) ) {
          c = 0;
          tt = current_weather;
          // 盡量往好天氣走
          r = random (12)-6;
          if (r > 0) r = 1; else if (r < 0) r = -1;
          t = tt + r;
          // 保證每次天氣都不一樣
          if ( t == tt )
            if (t >= 5) t--;
            else       t++;
          if (t < 0) t = 1;
          else if (t > 9) t = 8;
        }
        else
          t = random(5);

        current_weather = t;

// 這邊會有問題

        if (!undefinedp(weather[current_weather]["weather_msg"]))
        message("outdoor:vision", weather[current_weather]["weather_msg"]+"("+
                current_weather+")。\n",
                users());
        if( !undefinedp(weather[current_weather]["event_fun"]) )
                call_other (this_object(),weather[current_weather]["event_fun"]);

        if ((c=weather[current_weather]["length"]) <= 0) {
          call_out("update_weather", 10+random(11));
        }
        else
          call_out("update_weather", weather[current_weather]["length"]+random(11));
}

void update_day_phase ()
{
        remove_call_out("update_day_phase");

        reclaim_objects();
        current_day_phase = (++current_day_phase) % sizeof(day_phase);
        message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n",
                users());
        if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
                call_other(this_object(), day_phase[current_day_phase]["event_fun"]);
        // 儲存 clan 的 data
        CLAN_D->save();
        call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}

int show_time(object me)
{
  return current_day_phase;
}

// 雷雨一來就....hehe....
void event_thunder ()
{
  random(3)>0?weather_light = 1:weather_light=-1;
  message("outdoor:vision", "\n不遠的高空畫過一道閃電\n\n"+
          "不久後, 傳來震耳欲聾的雷聲....久久不絕....\n\n", users());
  call_out ("kill_badman", 3);
}

void kill_badman()
{
  object bad, *ob;
  int i, b, m, r,kee;

  remove_call_out ("kill_badman");

  m = 0;
  // 三次裡有一次會打雷, 惡人會遭報應
  r = random(3);
  ob = users();
  if (r == 0) {
    for(i=0; i<sizeof(ob); i++) {
      if( !environment(ob[i]) ) continue;
      if( !environment(ob[i])->query("outdoors") ) continue;
      b = ob[i]->query("bellicosity");
      if (b > m) { m = b; bad = ob[i]; }
    }
    if (m != 0 && bad) {
      // bad->query_temp("thunder") 是避雷效果，給以後的避雷針用
      // 從 0% - 100 %
      m = bad->query_temp("thunder");
      r = bad->query("kee");
      if (m < 0) m = 0;
      if (m > 100) m = 100;
      // 殺孽太重會被雷劈
      //原本的完全沒有散雷的作用..天呀...改
//    if( b > 500){
      if( b > 500 && m <random(101) ) {//看eq的機率.....
      if( !bad->is_fighting() && !bad->is_killing() ) {
        message("outdoor:vision",
          "霹靂的一聲，跟著傳來一道驚人的呼救聲，看來是有人被雷擊中了!!\n",
          ob, bad);
        tell_object (bad,
        "一道閃電從不遠的天上直直的命中你，你身上到處都是閃電過後留下的焦痕。\n");
//      bad->set("bellicosity", bad->query("bellicosity")*7/10);
//      扣的太多,有玩家及巫師反應,調降
        bad->set("bellicosity", bad->query("bellicosity")*2/10);
        kee = bad->query("max_kee") * (100-m)/200;
        bad->receive_damage("kee", kee);
}
      }
    }
  }
  else
      message("outdoor:vision", "轟隆隆的雷聲似乎漸漸遠去.......\n", ob);
}

string outdoor_room_description()
{
  string msg;

  msg = "    " + weather[current_weather]["desc_msg"] + "。\n";

  // 壞天氣看不到太陽，無法預測時間
  if (current_weather <= 5)
        msg += "    " + day_phase[current_day_phase]["desc_msg"] + "。\n";
  return msg;
}

string game_time()
{
        return CHINESE_D->chinese_date(time()*60);
}

// This function is to read a regular type of data table for day_phase and
// etc.
mapping *read_table(string file)
{
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn;

        line = explode(read_file(file), "\n");
        data = ({});
        for(i=0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !pointerp(field) ) {
                        field = explode( line[i], ":" );
                        continue;
                }
                if( !pointerp(format) ) {
                        format = explode( line[i], ":" );
                        continue;
                }
                break;
        }

        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
                sscanf( line[i], format[fn], data[rn][field[fn]] );
                fn = (++fn) % sizeof(field);
                if( !fn ) ++rn;
        }
        return data;
}


mapping *query_day_phase() { return day_phase; }

int query_weather_hurt() { return weather_hurt; }

void event_good_weather ()      { weather_hurt = 0; weather_light = 1; }
void event_water_weather()      { weather_hurt = 0; weather_light = -1; }
void event_light_rain ()        { weather_hurt = 1; weather_light = -1; }
void event_heave_rain ()        { weather_hurt = 2; weather_light = 0; }
void event_ice_rain ()          { weather_hurt = 3; weather_light = 1; }
void event_super_bad_weather () { weather_hurt = 4; weather_light = 0; }

int vision(object me)
{
  int           user, room, outdoors, rlight;
  object        env, *light;
  int           result;

  me = this_player();

  env = environment(me);

  if ( !env ) {
    me->move(VOID_OB);
    env = environment(me);
    if ( !env )
      return notify_fail ("你身處在虛無飄緲中，濛濛地一片﹐什麼也沒有。\n");
  }

  if (wizardp(me)) return 1;

  // light 代表人物身上是否有照明設備, 變數名稱取跟房間一樣
  light = all_inventory(me);
  for (result=0; result<sizeof(light); result++)
    if (light[result]->query("light_up") == -1 ||
        light[result]->query("had_light")) return 1;

  // 三更半夜
  if (current_day_phase == 11) rlight = 0;
  else if (current_day_phase == 0  || current_day_phase == 1 ||
           current_day_phase == 10 || current_day_phase == 9  )
    // 天暗外加壞天氣就看不見
    if (!weather_light) rlight = 0;
    // 天色昏暗
    else rlight = -1;
  // 壞天氣就視線模糊
  else rlight = weather_light;

  // 表示室內或室外
  if (env->query("outdoors")) outdoors = 1;

  // light_up 是定義在房間裡的變數, 代表有沒有燈光
  // 室外這變數無效, 只跟天候有關
  else room = env->query("light_up");

  user = 0;
  if (outdoors) user = rlight;
  else user = room;

  return user;
}

void check_heart_beat()
{
        object *user;
        int i;

        user=users();
        if(sizeof(user) >0)
        for(i=0;i<sizeof(user);i++)
        {
                if(wizardp(user[i]) && user[i]->query("env/check_heart"));
                  "/adm/daemons/temp.c"->record_heart_beat(user[i]);
                if(query_heart_beat(user[i]))
                continue ;
                if(user[i]->query_temp("have_no_heart_beat"))
                continue ;
                if(!user[i]->query("id")) continue;
                if(geteuid(user[i])=="MudOS") continue;
                "/adm/daemons/temp.c"->record_heart_beat(user[i]);
        }
        call_out("check_heart_beat",1);
}

