![Vulcano Logo](https://vulcanocrypto.com/wp-content/uploads/2018/03/Badge-Full-Color.svg)

Vulcano Cryptocurrency
&middot;
[![GitHub license](https://img.shields.io/github/license/vulcano-crypto/Vulcano.svg)](https://github.com/vulcano-crypto/Vulcano/blob/master/COPYING) [![Build Status](https://travis-ci.org/vulcano-crypto/Vulcano.svg?branch=master)](https://travis-ci.org/vulcano-crypto/Vulcano) [![GitHub version](https://badge.fury.io/gh/vulcano-crypto%2FVulcano.svg)](https://badge.fury.io/gh/vulcano-crypto%2FVulcano) [![Discord](https://img.shields.io/discord/374271866308919296.svg)](https://discord.me/vulcanocrypto)
=====

Vulcano (VULC) is a privacy oriented digital currency with Masternodes implemented.
Vulcano offers both SwiftTX and Obfuscation to enable speedy transactions.

## Specifications

| Specification         | Descriptor               |
|-----------------------|--------------------------|
| Ticker                | VULC                     |
| Algorithm             | NIST5                    |
| RPC Port              | 52541                    |
| P2P Port              | 62543                    |
| Block Spacing         | 90 Seconds               |
| Difficulty Algorithm  | Dark Gravity Wave v3.0   |
| Block Size            | 1MB                      |
| Mined/Minted Maturity | 67 Blocks (~100 Minutes) |
| Confirmation          | 6 Blocks (~9 Minutes)    |
| PoW Period            | nHeight ≤ 960            |
| PoS Period            | nHeight ≥ 961            |
| Protocol Support      | IPV4, IPV6, TOR          |
| PoS                   | Split Rewards            |

## PoW Block Reward

| Subsidy    | Block | PoW  | MN  | Circulation |
|------------|-------|------|-----|-------------|
| 95,000,000 | 1     | 100% | NA  | 95,000,000  |
| 500.0      | 2-960 | 35%  | 65% | 95,479,000  |

## PoS Block Rewards

| Subsidy | Block            | Budget | PoS  | MN  | Circulation |
|---------|------------------|--------|------|-----|-------------|
| 500.0   | 961-172800       | 0%     | 35%  | 65% | 181,396,500 |
| 375.0   | 172801-345600    | 10%    | 30%  | 60% | 246,194,250 |
| 281.25  | 345601-518400    | 10%    | 30%  | 60% | 294,792,563 |
| 210.938 | 518401-691200    | 10%    | 30%  | 60% | 331,241,297 |
| 158.203 | 691201-864000    | 10%    | 30%  | 60% | 358,577,848 |
| 118.652 | 864001-1036800   | 10%    | 30%  | 60% | 379,080,261 |
| 88.989  | 1036801-1209600  | 10%    | 30%  | 60% | 394,457,071 |
| 66.742  | 1209601-1382400  | 10%    | 30%  | 60% | 405,989,678 |
| 50.056  | 1382401-1555200  | 10%    | 30%  | 60% | 414,639,133 |
| 37.54   | 1555201-1728000  | 10%    | 30%  | 60% | 421,126,225 |
| 18.771  | 1728001-Infinite | 10%    | 30%  | 60% | N/A         |
