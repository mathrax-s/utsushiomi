# うつしおみ
[![Build Status](https://travis-ci.org/pages-themes/minimal.svg?branch=master)](https://travis-ci.org/pages-themes/minimal) [![Gem Version](https://badge.fury.io/rb/jekyll-theme-minimal.svg)](https://badge.fury.io/rb/jekyll-theme-minimal)

*Minimal is a Jekyll theme for GitHub Pages. You can [preview the theme to see what it looks like](http://pages-themes.github.io/minimal), or even [use it today](#usage).*

![Thumbnail of minimal](thumbnail.png)

## 作品の紹介

[![うつしおみ](http://img.youtube.com/vi/HiOy_eePyWg/0.jpg)](http://www.youtube.com/watch?v=HiOy_eePyWg "うつしおみ")

たくさんの小さな木のオブジェがのったテーブルがつながっています。その木のオブジェは触れると音を奏でます。

音を頼りにしてもいいし、手触りを頼りにいいし（実は光や香りも変化していて）、いろいろな感覚を頼りにしながら、前に歩いてゆく体験型の作品です。

この作品は、目が不自由でも、耳が不自由でも、車椅子の高さでも、そして小さな子供の目線でも、それぞれの感覚で体験できるように考えました。

<a href = "https://mathrax.com/contents/page10523">作品「うつしおみ」について詳しく（MATHRAXのサイトへ）</a>

---



### 基本的なシステム

[![基本的なシステム](https://github.com/mathrax-s/utsushiomi/raw/garage/system_basic.png)]("system_basic")

テーブルにある木のオブジェは、触れると音を奏でます。

木のオブジェは、各テーブルに12個ずつあり、各テーブルに1つずつあるスピーカーから音を出力します。

このテーブルが14台あり、つなげて長くしています。

---



### キツネのあるシステム


[![基本的なシステム](https://github.com/mathrax-s/utsushiomi/raw/garage/system_fox.png)]("system_fox")

テーブルのうちいくつかに、キツネの形をした木の彫刻がのっています。その背中に触れても音を奏でます。

---


#### **木のオブジェに触れたことを知らせる「タッチセンサ」**

PSoC4をタッチセンサとしてプログラムしています。PSoC4は、シリアル通信でRaspberryPiに情報を伝えます。

キツネのなかにも、PSoC4のタッチセンサが入っています（細長いので2つ入っています）。

キツネのタッチセンサは、いったんESP32へシリアル通信で情報を伝えた後、ESP32がWIFIで無線信号に変換し、RaspberryPiに情報を伝えます。

キツネのオブジェはWIFIの届く範囲で、遠く離れた位置に配置することもできます。

##### **補足**

今回の作品には直接関係ありませんが、キツネのタッチセンサは今後のプロジェクトの拡張性を考え、センサの通信ケーブルが長くなってもよいようにRS485で通信する設計としています。

タッチセンサのプログラムの種類

- 木のオブジェにつかうタッチセンサのプログラム（RaspberryPiと直接シリアル通信する）
- キツネのタッチセンサのプログラム（ESP32とRS485でシリアル通信する）
- キツネのタッチセンサをWIFIに変換するプログラム（ESP32がRS485で受信しOSCに変換し送信する）



---

#### **タッチの情報を、音を奏でるプログラムへ伝える「NODE-RED」**

タッチした情報が届いたら、次に解説する「音を奏でるプログラム」の「PureData」に伝えます。

PureDataでもタッチの情報をシリアル通信で受信できますが、機能拡張が必要で更新履歴が古く動作が不安定なため、NODE-REDが担当しています。

NODE-REDはタッチの情報をOSCに変換し、PureDataに伝えます。（PureDataのネットワーク通信はとても安定して動作します）

![NODE-RED](https://github.com/mathrax-s/utsushiomi/blob/garage/nde-red-preview.png?raw=true)

---

#### **音を奏でるプログラム「PureData」**

![PureData](https://github.com/mathrax-s/utsushiomi/blob/garage/puredata-preview.png?raw=true)

RaspberryPiで起動している音響ソフトのPureData（以下Pd）が奏でます。

Pdではタッチの情報をOSCで受信し、シンプルに0〜12までの数値にします。

タッチしていないときが「0」。タッチすると木のオブジェの並ぶ順番で「1〜12」となります。

