// Room: /open/gsword/room/wghouse.c
inherit ROOM;

void create ()
{
  set ("short", "藏經閣門口");
  set ("long", @LONG
這是藏經閣的門口，你看到門前一個碩大的匾額(sign)，上邊以楷書
寫著--藏經閣--三個大字，在門口的兩側有著兩座栩栩如生的雕像，
似乎直盯著你看。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/north",
  "east" : "/open/gsword/room/wghouse1",
]));

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "            ,,   ;;                                               ,,, 
          ';;  ,,;,,,;;        ,,,                   ,,,;';,  ;;'''';;
      ;;;'';;   ;  ,,          ;;     ;;;;''''       ;; ,,;;   ;,;' ;;
                ;;  ';        ;' ;;, ,   ,,  ;,       ;'' ;;   ; ,,,;;
     ,  ,,,,,,;';;''        ,;' ,;'  ;; ;;' ;'        ;,;'';;,,'''  ;;
     ;;  ; ,,,,,,;,  ,     ';'';'   ;' ,;  ';,,       ;   ,;'';;    ;;
     ;;''; ;';;  '; ,;'      ,;',;, ';, ';   ''       ;  ' ';;;     ;;
        ,; ;''';; ;;;'      ;;;'' '   ' ,,,,,,        ;   ,;' ';,,  ;;
   '';;';' ;,,,'   ;;         ,  ;, '''';;''         ,; ,';,,,;;;''';;
     ;' ;  ; ;,,, ;';;,  ,';, ';  '     ;;  ,,,,     ;;   ;;  ,;',,,;;
   ,'  ;' ''    ;;'  ';,;; ';     ,,;'''''''''''''   ';    ;''''  ';;;
",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/chenun.c" : 1,
]));

  set("light_up", 1);
  setup();
}
int valid_leave(object me, string dir)
{
if( dir=="east" && present("un", environment(me)))
   return 0;
return ::valid_leave(me,dir);
}
