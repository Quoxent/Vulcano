import socket

seeders = [
    'vulcseed.mempool.pw',
    'vulcseed1.vulcano.io',
    'vulcseed2.vulcano.io',
    'vulcseed3.vulcano.io',
    'vulcseed4.vulcano.io',
    'vulcseed5.vulcano.io',
    'vulcseed1.vulcanocrypto.site',
    'vulcseed2.vulcanocrypto.site',
    'vulcseed3.vulcanocrypto.site',
    'vulcseed4.vulcanocrypto.site',
    'vulcseed5.vulcanocrypto.site'
]

for seeder in seeders:
    try:
        ais = socket.getaddrinfo(seeder, 0)
    except socket.gaierror:
        ais = []
    
    # Prevent duplicates, need to update to check
    # for ports, can have multiple nodes on 1 ip.
    addrs = []
    for a in ais:
        addr = a[4][0]
        if addrs.count(addr) == 0:
            addrs.append(addr)
    
    print(seeder + ' = ' + str(len(addrs)))
