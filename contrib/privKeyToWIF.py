import binascii
import hashlib
import sys

def privateKey_to_WIF(pre, pk): 
    privWIF1 = hashlib.sha256(binascii.unhexlify(pre + pk)).hexdigest()
    privWIF2 = hashlib.sha256(binascii.unhexlify(privWIF1)).hexdigest()
    privWIF3 = pre + pk + privWIF2[:8]

    pubnum = int(privWIF3, 16)
    pubnumlist = []
    while pubnum != 0: pubnumlist.append(pubnum % 58); pubnum /= 58
    WIF = ''
    for l in ['123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz'[x] for x in pubnumlist]:
        WIF = l + WIF
    return WIF

# mainnet = 'd4'
# testnet = 'ef'
pre = sys.argv[1]
k = sys.argv[2]
rs =  privateKey_to_WIF(pre, k)
print(rs)