以下、PokemonBDSP ver1.1.2においてArduino Leonardoを用いて動作確認済。
これはメニューバグ(BDSPver1.1.1,ver1.1.2,ver1.1.3で確認されているもの)によりアイテムを増殖させるプログラムです。ご利用は自身の責任のもとで行ってください。以下参考資料

Arduino　Leonardoの導入：https://pokemonit.com/micon-introduction/ 

NintendoSwitchControlLibraryのインストール：https://github.com/lefmarna/NintendoSwitchControlLibrary

メニューバグver1.1.3のやり方：https://youtu.be/kvaZYAzIz1w  ver1.1.2：https://youtu.be/xHTyVEa0ZF8  ver1.1.1：https://youtu.be/5M09vQNJYXc

手順
①ボックス内のポケモンに「同じアイテム」を30体全員に持たせる

②バッグ内にあるアイテムの個数を数えて下のconst int already_collect_items=に代入する。

③レポートを書き（重要！）、メニューバグを発生させ、周りにNPCのいない場所で「ポケモン」→「ボックス」→Xボタン×5回→「ポケモン」→「ボックス」→Xボタン（道具が全て見えている状態）をしたのち、

ボックス左上のポケモンにカーソルを合わせてからSwitch本体またはスタンドにマイコンを挿す

④画面左上で「べんり」ではなく「つうじょう」で回収が行われていることを確認する（「べんり」になってしまったらマイコンを外してポケモンにカーソルを合わせて再び挿す。成功するまで行う）

⑤少なくとも一周は観察しておかしい挙動をしていないか確認する

⑥回収が終わると自動的に③の状態でストップするのでそこでマイコンを外す


