# handwarmer
"convert electricity to heat"

I took the handwarmer.c code written by Scott Vokes, this was essentially an exercise in learning to build multi-platform docker images with docker buildx.

https://gist.github.com/silentbicycle/8223201 
https://twitter.com/silentbicycle

`docker buildx build --push --platform linux/arm/v7,linux/arm64/v8,linux/amd64 --tag pvnovarese/handwarmer:latest .`

https://www.docker.com/blog/multi-arch-build-and-images-the-simple-way/
