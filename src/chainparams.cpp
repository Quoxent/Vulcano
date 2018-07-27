// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2017-2018 The Vulcano developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}
//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions

static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
        (0, uint256("0x000002c5551b617c4f02f6be4aa8a03e9a17fec08524bf4cf97fc6d9be5a856e"));
 
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1532628450,// * UNIX timestamp of last checkpoint block
    0,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
	boost::assign::map_list_of(0, uint256("0x00000825187e9a21962b3c7b7d516ed84ffd8a0d1024249e87904802e363d43e"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1532628451,
    0,
    250};
static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1532628452,
    0,
    100};
class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x08;
        pchMessageStart[1] = 0x02;
        pchMessageStart[2] = 0x01;
        pchMessageStart[3] = 0x17;
	    vAlertPubKey = ParseHex("04579f18934b3ef39094a9999e45506a1935662d0cd4e504d07beb53b8a1bfd78d81bee47e65119318397809420d5320e3c7b2aaae58580db48c38a4e6d4f0f919");
        nDefaultPort = 52543;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // Vulcano starting difficulty is 1 / 2^12
        nMaxReorganizationDepth = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 90; // Vulcano: 1.5 minutes
        nTargetSpacingSlowLaunch = 5 * 90;  // Vulcano: 7.5 minutes (Slow launch - Block 300)
	    nTargetSpacing = 1 * 90; // Vulcano: 1.5min after block 300
        nLastPOWBlock = 1; // Vulcano: straight to PoS
        nLastPOWBlockOld = 1; // Vulcano: straight to PoS
		nLastSeeSawBlock = 1; // Vulcano: straight to PoS split rewards
	    nRampToBlock = 1; // Slow start, ramp linearly to this block
        nMaturity = 66; // 99 Minutes
	    nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 1;
	    nMaxMoneyOut = 21525720 * COIN; // Year 2
	
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;

        const char* pszTimestamp = "November 30 2017 - Niger Approves Armed U.S. Drone Flights, Expanding Pentagon’s Role in Africa";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 50 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04243e8da79e117dba99d89a2da6ed761af43175227d19caaffea72398514962af9701478a69410b8158e190ae36d50a1f7325eba3df9559ad345db0cb72bfe2e2") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1532628450;
        genesis.nBits = 504365055;
        genesis.nNonce = 2104975; 

	    hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000002c5551b617c4f02f6be4aa8a03e9a17fec08524bf4cf97fc6d9be5a856e"));
	    assert(genesis.hashMerkleRoot == uint256("0x77976d6bd593c84063ac3937525bc15e25188d96871b13d4451ffc382999f64f"));

        vSeeds.push_back(CDNSSeedData("vulcseed1.vulcanocrypto.com", "vulcseed1.vulcanocrypto.com"));      // Single node address
        vSeeds.push_back(CDNSSeedData("vulcseed2.vulcanocrypto.com", "vulcseed2.vulcanocrypto.com")); 	   // Single node address
        vSeeds.push_back(CDNSSeedData("vulcseed3.vulcanocrypto.com", "vulcseed3.vulcanocrypto.com"));      // Single node address
	    vSeeds.push_back(CDNSSeedData("vulcseed4.vulcanocrypto.com", "vulcseed4.vulcanocrypto.com"));      // Single node address
        vSeeds.push_back(CDNSSeedData("vulcseed5.vulcanocrypto.com", "vulcseed5.vulcanocrypto.com"));      // Single node address
        vSeeds.push_back(CDNSSeedData("vulcseed1.vulcano.io", "vulcseed1.vulcano.io"));      // Single node address
        vSeeds.push_back(CDNSSeedData("vulcseed2.vulcano.io", "vulcseed2.vulcano.io")); 	 // Single node address
        vSeeds.push_back(CDNSSeedData("vulcseed3.vulcano.io", "vulcseed3.vulcano.io"));      // Single node address
	    vSeeds.push_back(CDNSSeedData("vulcseed4.vulcano.io", "vulcseed4.vulcano.io"));      // Single node address
        vSeeds.push_back(CDNSSeedData("vulcseed5.vulcano.io", "vulcseed5.vulcano.io"));      // Single node address
        
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 70); // V
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 18); // 8
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212); // 2
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
	    //BIP44 as defined by https://github.com/bitcoin/bips/blob/master/bip-0044.mediawiki
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container<std::vector<unsigned char> >();

	    convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));
        
	    fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;
        
	    nPoolMaxTransactions = 3;
        strSporkKey = "046537ca239799bbe3c511a44b584eb8ffa2d38a54bbc8af2577c4a92b2b741270ca23e581c91a6f004f9bf4719f611dc1690b966a8bf8b60603dde0b21fe30696";
        strObfuscationPoolDummyAddress = "VLG21KzfyugcFa19jgDNTf516f7YhXbRC2";
        nStartMasternodePayments = 1511092620; 
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;
/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0xb5;
        pchMessageStart[1] = 0xd9;
        pchMessageStart[2] = 0xf4;
        pchMessageStart[3] = 0xa0;

	    vAlertPubKey = ParseHex("04795fde7bfc6347248a901aca81dd6a9f3acdeb5272f1c831f5147b139a4e1bacaa253541d9ebdfba982fb5cc45df3e34a8e98cdce9329037f009af217bc64ed9");
        nDefaultPort = 42133;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 30; // 30 Seconds
        nTargetSpacing = 1 * 30;  // 30 Seconds
	    nTargetSpacingSlowLaunch = 1 * 30; // Kludgy but don't want to check for testnet each time in GetNextWorkRequired

        nLastPOWBlock = 1000;
        nLastPOWBlockOld = 1100;
		nLastSeeSawBlock = 1200;
        nMaturity = 15;
        nMaxMoneyOut = 33284220 * COIN; // 2032 Maximum
        nRampToBlock = 100;

        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1532628451;
        genesis.nNonce = 1908779;
        genesis.nBits = 504365055;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000825187e9a21962b3c7b7d516ed84ffd8a0d1024249e87904802e363d43e"));
        assert(genesis.hashMerkleRoot == uint256("0x77976d6bd593c84063ac3937525bc15e25188d96871b13d4451ffc382999f64f"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("test-node01.vulcanocrypto.com", "test-node01.vulcanocrypto.com"));
        vSeeds.push_back(CDNSSeedData("test-node01.vulcano.io", "test-node01.vulcano.io"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 65); // Testnet vulcano addresses start with 'T'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 12);  // Testnet vulcano script addresses start with '5' or '6'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet vulcano BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet vulcano BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet vulcano BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x01)(0x00)(0x00)(0x80).convert_to_container<std::vector<unsigned char> >();
        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));
        fRequireRPCPassword = true;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;
        nPoolMaxTransactions = 2;
        strSporkKey = "04a24c7d50706b3234a8478e84218ddf05247a816441a016b05062c00b55f7b23fa9ae20a2e22e1febc112fb56b0b9ed1639f63593e5591ba1c2db75819780130f";
        strObfuscationPoolDummyAddress = "TUTsbvDcUEk4fuxnVVvHUZd2ziDs4i9czv";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;
/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // Vulcano: 1 day
        nTargetSpacing = 1 * 60;        // Vulcano: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1532628452;
        genesis.nBits = 545259519;
        genesis.nNonce = 1;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 51476;
        assert(hashGenesisBlock == uint256("0x6d78a65fcf8b7db69a58984cfb042cadcd8afa7243c3d6e54dbff45566fea919"));
        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;
/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }
    //! Published setters to allow changing values in unit test cases
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
};
static CUnitTestParams unitTestParams;
static CChainParams* pCurrentParams = 0;
CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}
const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}
CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}
void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}
bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;
    SelectParams(network);
    return true;
}
