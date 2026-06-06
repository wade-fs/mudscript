#include <ansi.h>
#include "moon.h"
inherit NPC;
inherit SSERVER;


void create()
{
    set_name("嫦娥" ,({"the goddess of the moon","moon","goddess","the"}) );
    set("long","傳說中在月亮上等待著回地球的女性。\n");
  set("gender","女性");
  set("combat_exp",2900000);
  set("age",1021);
  set("cor",32);
  set("str",20);
  set("kar",100);

  set("kee",4900);
  set("max_kee",4900);
  set("sen",2200);
  set("max_sen",2200);
  set("gin",2500);
  set("max_gin",2500);
  set("force",4200);
  set("max_force",4200);
  set("bellicosity",4000);
  set("chat_chance_combat", 25);
  set_temp("apply/armor",400);
  set_temp("apply/damage",180);
  set("force_factor",20);
  set_skill("dodge",300);
  set_skill("parry",300);
  set_skill("move",300);

  set_skill("unarmed",280);
  set("attribute","fire");
  set("chat_chance",90);
  setup();
  add_money("gold",20);

}
mapping local = ([
    "惡人谷"           :"/open/badman/room",
    "丐幫"           :"/open/beggar/room/beg1",
    "丐幫"           :"/open/beggar/room/beg2",

    "少林寺"           :"/open/bonze/room",
    "京城"           :"/open/capital/room",
    "鏡月島"           :"/open/dancer/room",
    "銀針門"           :"/open/doctor/room",
    "火龍幻界"           :"/open/fire-hole",
    "金刀門"           :"/open/gblade/room",
    "魔刀門"           :"/open/gblade/mroom",
    "蒙古高原"           :"/open/grassland",
    "蜀中城"           :"/open/gsword/room",
    "總理衙門"           :"/open/hall",
    "殺手區域"           :"/open/killer/room",
    "絕情門"           :"/open/love/room",
    "長沙鎮"           :"/open/marksman/room",
    "長白山"           :"/open/mon",
    "極北冰原"           :"/open/north-polar",
    "平南城"           :"/open/ping/room",
    "冥蠱魔教"           :"/open/poison/room",
    "楓林港"           :"/open/port/room",
    "聖火教"           :"/open/prayer/room",
    "儒門"           :"/open/scholar/room",
    "雪蒼派"           :"/open/snow/room",
    "凌雲村"           :"/open/start/room",
    "天龍寺"           :"/open/tailong/room",
    "天道派"           :"/open/tendo/room",
    "金風細雨樓"           :"/open/wind-rain",
    "正晴武館"           :"/open/wu/room",

    ]);
void reset()
{
  int rand,pick,n;  
  string c_name,dir,file;
  mixed files;
  if(!environment()) return ;
  rand = random(sizeof(local));
  c_name = keys(local)[rand];
  dir = values(local)[rand];
  files = get_dir(dir+"/");
  CHANNEL_D->do_channel(this_object() , CHANNEL , "哎呀，一堆死兔子跑到「"+c_name+"」去了！\n");
  n = random(3)+5;
  while(1)
  {
    file = files[random(sizeof(files))];
    if(sscanf(file,"%*s.c") != 1) continue;
    new(__DIR__"rabbit.c")->move(dir+"/"+file);
  tell_room(load_object("/open/wiz/hall1"),
      sprintf("file = %s/%s \n ",dir,file));

    pick++; 
    if(pick == n) break;
  }

}
